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
        printf("%.2f\n", 2.0 * PI * C.r);
    }
    
    return 0;
}