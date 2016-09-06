#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EPS 1e-7

class Point
{
public:
    double x;
    double y;
    
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) { }
    
    bool operator==(const Point &p) const
    {
        return p.x == x && p.y == y;
    }
    
    double distTo(const Point &p) const
    {
        return hypot(p.x - x, p.y - y);
    }
    
};

inline bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

inline double D(const Point &P, const Point &Q, const Point &R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

class Line
{
public:
    double a, b, c;
    
    Line(const Point &p, const Point &q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - p.y * q.x;
        
        auto k = a ? a : b;
        a /= k;
        b /= k;
        c /= k;
    }
    
    bool operator==(const Line &r) const
    {
        return equals(a, r.a) && equals(b, r.b) && equals(c, r.c);
    }
    
    pair<int, Point> intersection(const Line &l)
    {
        double det = a * l.b - b * l.a;
        
        if (equals(det, 0)) {
            // parallel or coincident
            int qtd = (l == *this) ? -1 : 0;
            return make_pair(qtd, Point());
        }
        
        // concurrent
        double x = (-c * l.b + l.c * b) / det;
        double y = (-l.c * a + c * l.a) / det;
        return make_pair(1, Point(x, y));
    }
    
    Point closest(const Point &P)
    {
        double den = a * a + b * b;
        double x = (b * (b * P.x - a * P.y) - a * c) / den;
        double y = (a * (-b * P.x + a * P.y) - b * c) / den;
        return Point(x, y);
    }
    
};

class Segment
{
public:
    Point A;
    Point B;
    
    Segment(const Point &_A, const Point &_B) : A(_A), B(_B) { }

    bool operator==(const Segment &s) const
    {
        return (s.A == A && s.B == B) || (s.A == B && s.B == A);
    }

    double length() const
    {
        return hypot(A.x - B.x, A.y - B.y);
    }

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

    Point closest(const Point &P)
    {
        Line r(A, B);
        Point Q = r.closest(P);
        
        if (contains(Q)) {
            return Q;
        }
        
        auto distA = P.distTo(A);
        auto distB = P.distTo(B);
        
        return distA <= distB ? A : B;
    }

    pair<int, Point> intersection(const Segment &s)
    {
        if (s == *this) {
            return make_pair(-1, Point()); // identical
        }
        
        if (!intersects(s)) {
            return make_pair(0, Point()); // doesn't intersect
        }
        
        Line l1(A, B);
        Line l2(s.A, s.B);
        
        pair<int, Point> lineIntersection = l1.intersection(l2);
        return make_pair(1, lineIntersection.second);
    }
};

int main()
{
    ll n;
    cin >> n;
    
    printf("INTERSECTING LINES OUTPUT\n");
    
    for (int i = 0; i < n; i++) {
        ll x1, y1;
        ll x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Line l1(Point(x1, y1), Point(x2, y2));
        
        ll x3, y3;
        ll x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;
        Line l2(Point(x3, y3), Point(x4, y4));
        
        pair<int, Point> lineIntersection = l1.intersection(l2);
        if (lineIntersection.first == -1) {
            printf("LINE");
        } else if (lineIntersection.first == 0) {
            printf("NONE");
        } else {
            printf("POINT %.2f %.2f", lineIntersection.second.x == 0 ? 0 : lineIntersection.second.x,
                                      lineIntersection.second.y == 0 ? 0 : lineIntersection.second.y);
        }
        printf("\n");
    }
    
    printf("END OF OUTPUT\n");
    
    return 0;
}
