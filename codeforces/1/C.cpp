#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793
#define EPS 1e-4

using Point = pair<double, double>;

class Polygon
{
public:
    vector<Point> vertices;
    int n;
    
    Polygon(const vector<Point> &_vertices) : vertices(_vertices), n(_vertices.size())
    {
        vertices.push_back(vertices[0]);
    }

    double area() const
    {
        double a = 0;
        for (int i = 0; i < n; i++) {
            a += vertices[i].first * vertices[i + 1].second;
            a -= vertices[i+1].first * vertices[i].second;
        }
        return 0.5 * fabs(a);
    }
};

double dist(const Point &p1, const Point &p2)
{
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

double gcd(double a, double b)
{
    return fabs(b) < EPS ? a : gcd(b, fmod(a, b));
}

int main()
{
    Point p1, p2, p3;
    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;
    
    Polygon triangle({p1, p2, p3});
    double area = triangle.area();
        
    double a = dist(p1, p2);
    double b = dist(p2, p3);
    double c = dist(p3, p1);
        
    double circleRadius = (a*b*c) / (4.0*area);
    
    double A = acos((b*b + c*c - a*a) / (2*b*c));
    double B = acos((a*a + c*c - b*b) / (2*a*c));
    double C = acos((a*a + b*b - c*c) / (2*a*b));
        
    double n = PI / gcd(gcd(A, B), C);
    double ans = n/2 * circleRadius*circleRadius * sin(2*PI / n);
    printf("%.6f\n", ans);
    
    return 0;
}
