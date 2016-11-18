#include <bits/stdc++.h>

using namespace std;

#define oo 9223372036854775807
#define EPS 1e-6
#define PI 3.141592653589793

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

inline bool equals(double x, double y)
{
    return fabs(x - y) < EPS;
}

class Point
{
public:
    double x, y;
    
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    
    double distance(const Point &p) const
    {
        return hypot(x - p.x, y - p.y);
    }
      
};

class Circle
{
public:
    Point C;
    double r;
    
    Circle(const Point &_C = Point(), double _r = 0) : C(_C), r(_r) {} 
    
    typedef enum { IN, OUT, ON } PointPosition;

    PointPosition position(const Point& P) const
    {
        auto d = P.distance(C);
        return equals(d, r) ? ON : (d < r ? IN : OUT);
    }
    
};

bool from2PointsAndRadius(const Point &P, const Point &Q, double r, Circle &c)
{
    double d2 = (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
    double det = r * r / d2 - 0.25;

    if (det < 0.0)
        return false;

    double h = sqrt(det);

    auto x = (P.x + Q.x) * 0.5 + (P.y - Q.y) * h;
    auto y = (P.y + Q.y) * 0.5 + (Q.x - P.x) * h;

    c = Circle(Point(x, y), r);

    return true;
}

int main()
{
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;
        
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        
        double r;
        cin >> r;
                
        bool possible = false;
        for (int i = 0; i < n && !possible; i++) {
            for (int j = i + 1; j < n && !possible; j++) {
                Circle c1, c2;
                bool succ1 = from2PointsAndRadius(points[i], points[j], r, c1);
                bool succ2 = from2PointsAndRadius(points[j], points[i], r, c2);
                
                for (int i = 0; i < n; i++) {
                    if (succ1 && c1.position(points[i]) == Circle::PointPosition::OUT) succ1 = false;
                    if (succ2 && c2.position(points[i]) == Circle::PointPosition::OUT) succ2 = false;
                }
                
                if (succ1 || succ2) possible = true;
            }
        }
        
        if (possible) {
            printf("The polygon can be packed in the circle.\n");
        } else {
            printf("There is no way of packing that polygon.\n");
        }
    }
    
    return 0;
}
