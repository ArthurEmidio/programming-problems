#include <bits/stdc++.h>

using namespace std;

#define oo 9223372036854775807
#define EPS 1e-6
#define PI 3.14159265358979323846

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
    
};

Circle circle_from_3_points(const Point& P, const Point& Q, const Point& R)
{
    auto a = 2*(Q.x - P.x);
    auto b = 2*(Q.y - P.y);
    auto c = 2*(R.x - P.x);
    auto d = 2*(R.y - P.y);

    auto det = a*d - b*c;

    if (equals(det, 0))
        return Circle();

    auto k1 = (Q.x*Q.x + Q.y*Q.y) - (P.x*P.x + P.y*P.y);
    auto k2 = (R.x*R.x + R.y*R.y) - (P.x*P.x + P.y*P.y);

    auto cx = (k1*d - k2*b)/det;
    auto cy = (a*k2 - c*k1)/det;

    Point C(cx, cy);
    auto r = C.distance(P);

    return Circle(C, r);
}

int main()
{
    for (;;) {
        Point p1, p2, p3;
        cin >> p1.x;
        if (cin.eof()) break;
        cin >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        
        Circle C = circle_from_3_points(p1, p2, p3);
        Point c = C.C;
        
        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n", c.x < 0 ? '+' : '-',
                                                           fabs(c.x),
                                                           c.y < 0 ? '+' : '-',
                                                           fabs(c.y),
                                                           C.r);
        
        double end = -(C.r * C.r) + c.x*c.x + c.y*c.y;
        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n\n", c.x < 0 ? '+' : '-',
                                                              fabs(c.x) * 2,
                                                              c.y < 0 ? '+' : '-',
                                                              fabs(c.y) * 2,
                                                              end < 0 ? '-' : '+',
                                                              fabs(end));
    }
    
    return 0;
}