#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EPS 1e-7

inline bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

class Point
{
public:
    double x;
    double y;
    
    Point(double _x, double _y) : x(_x), y(_y) { }
};

inline double D(const Point &P, const Point &Q, const Point &R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

class Segment
{
public:
    Point A;
    Point B;
    
    Segment(const Point &_A, const Point &_B) : A(_A), B(_B) { }

    bool contains(const Point &P) const
    {
        if (A.x == B.x) {
            return min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y);
        } else {
            return min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x);
        }
    }

    bool intersects(const Segment &s) const
    {
        auto d1 = D(A, B, s.A);
        auto d2 = D(A, B, s.B);
        
        if ((equals(d1, 0) && contains(s.A)) || (equals(d2, 0) && contains(s.B))) {
            return true;
        }
        
        auto d3 = D(s.A, s.B, A);
        auto d4 = D(s.A, s.B, B);
        
        if ((equals(d3, 0) && s.contains(A)) || (equals(d4, 0) && s.contains(B))) {
            return true;
        }
        
        return (d1 * d2 < 0) && (d3 * d4 < 0);
    }

};

int main()
{
    ll n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        ll xstart, ystart, xend, yend;
        ll xleft, ytop, xright, ybottom;
        cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;
        
        if (xleft > xright) swap(xleft, xright);        
        if (ytop < ybottom) swap(ytop, ybottom);
        
        Segment s(Point(xstart, ystart), Point(xend, yend));
        
        Segment s1(Point(xleft, ytop), Point(xleft, ybottom));
        Segment s2(Point(xleft, ybottom), Point(xright, ybottom));
        Segment s3(Point(xright, ybottom), Point(xright, ytop));
        Segment s4(Point(xright, ytop), Point(xleft, ytop));
        
        if (s.intersects(s1) || s.intersects(s2) || s.intersects(s3) || s.intersects(s4) ||
            (xstart >= xleft && xstart <= xright && ystart <= ytop && ystart >= ybottom &&
                 xend >= xleft && xend <= xright && yend <= ytop && yend >= ybottom)) {
            cout << 'T' << endl;
        } else {
            cout << 'F' << endl;
        }
    }
    
    return 0;
}
