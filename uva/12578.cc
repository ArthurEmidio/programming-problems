#include <bits/stdc++.h>

using namespace std;

#define oo 9223372036854775807
#define EPS 1e-6

const double PI = acos(-1);

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
    int n;
    cin >> n;
    while (n--) {
        int L;
        cin >> L;
        
        double w = (3 * L) / 5.0;
        double r = L / 5.0;
        
        double redArea = PI * r * r;
        double greenArea = (w * L) - redArea;
        
        printf("%.2f %.2f\n", redArea, greenArea);
    }
    
    return 0;
}
