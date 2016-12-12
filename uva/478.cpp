#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793
#define EPS 1e-7

typedef long long ll;
using Point = pair<double, double>;

bool equals(double x, double y)
{
    return fabs(x - y) < EPS;
}

double dist(const Point &p1, const Point &p2)
{
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

double D(const Point &P, const Point &Q, const Point &R)
{
    return (P.first * Q.second + P.second * R.first + Q.first * R.second) - (R.first * Q.second + R.second * P.first + Q.first * P.second);
}

double angle(const Point &P, const Point &A, const Point &B)
{
    double ux = P.first - A.first;
    double uy = P.second - A.second;
    
    double vx = P.first - B.first;
    double vy = P.second - B.second;
    
    double num = ux * vx + uy * vy;
    double den = hypot(ux, uy) * hypot(vx, vy);
    
    return acos(num / den);
}

class Circle
{
public:
    Point center;
    double radius;
    
    Circle(const Point &_center = Point(), double _radius = 0) : center(_center), radius(_radius) {}

    bool contains(const Point &p)
    {
        double distance = dist(p, center);
        return !equals(distance, radius) && distance < radius;
    }

};

class Polygon
{
public:
    Circle circle;
    vector<Point> vertices;
    int n;
    
    Polygon(const vector<Point> &_vertices) : vertices(_vertices), n(_vertices.size())
    {
        vertices.push_back(vertices[0]);
    }
    
    Polygon(const Circle &_circle) : circle(_circle), n(0) {}

    double area() const
    {
        double a = 0;
        for (int i = 0; i < n; i++) {
            a += vertices[i].first * vertices[i + 1].second;
            a -= vertices[i+1].first * vertices[i].second;
        }
        return 0.5 * fabs(a);
    }
    
    bool contains(const Point &P) const
    {
        if (n < 3) return false;
        
        double sum = 0;
        for (int i = 0; i < n; i++) {
            double d = D(P, vertices[i], vertices[i + 1]);
            if (equals(d, 0)) return false; // point on vertices/edges
            
            double a = angle(P, vertices[i], vertices[i + 1]);
            sum += d > 0 ? a : -a;
        }
        return equals(fabs(sum), 2 * PI);
    }
};

int main()
{
    vector<Polygon> polygons;    
    for (int i = 1; ; i++) {
        char c;
        cin >> c;
        if (c == '*') break;
        
        if (c == 'c') {
            Circle c;
            cin >> c.center.first >> c.center.second >> c.radius;
            polygons.push_back(Polygon(c));
        } else if (c == 'r') {
            vector<Point> points(4);
            Point tl, lr;
            cin >> tl.first >> tl.second >> lr.first >> lr.second;
            points[0] = tl;
            points[1] = Point(lr.first, tl.second);
            points[2] = lr;
            points[3] = Point(tl.first, lr.second);
            polygons.push_back(Polygon(points));
        } else {
            vector<Point> points(3);
            cin >> points[0].first >> points[0].second >> points[1].first >> points[1].second >> points[2].first >> points[2].second;
            polygons.push_back(Polygon(points));
        }
    }
    
    for (int i = 1; ; i++) {
        double x, y;
        cin >> x >> y;
        if (x == 9999.9 && y == 9999.9) break;
        Point p(x, y);
        
        vector<int> contain;
        for (int i = 0; i < polygons.size(); i++) {
            Polygon &polygon = polygons[i];
            bool doesContain = polygon.n == 0 ? polygon.circle.contains(p) : polygon.contains(p);
            if (doesContain) contain.push_back(i + 1);
        }
        
        if (contain.empty()) {
            printf("Point %d is not contained in any figure\n", i);
        } else {
            for (int idx : contain) {
                printf("Point %d is contained in figure %d\n", i, idx);
            }
        }
    }
    
    return 0;
}
