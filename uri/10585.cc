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
    
    bool operator<(const Point &p) const
    {
        return fabs(x - p.x) < EPS ? (p.y - y) > -EPS : p.x - x > -EPS;
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
    
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    
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
    
    bool operator<(const Line &l) const
    {
        return make_pair(make_pair(a, b), c) < make_pair(make_pair(l.a, l.b), l.c);
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
    
    inline double distance(const Point &p) const
    {
        return fabs(a * p.x + b * p.y + c) / hypot(a, b);
    }
    
    inline bool contains(const Point &p) const
    {
        return equals(distance(p), 0);
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
        Line r(P, A);
        Line q(P, B);
        if (!(r == q)) return false;
        
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
    int c;
    cin >> c;
    
    while (c--) {
        int n;
        cin >> n;
        
        set<Point> points;
        for (int i = 0; i < n; i++) {
            Point p;
            cin >> p.x >> p.y;
            points.insert(p);
        }
        
        vector<Point> candidates(n);
        Point &p1 = *(points.begin());
        
        int i = 0;
        for (const Point &p : points) {
            candidates[i++] = p1 + p;
        }
        
        bool exists;
        for (const Point &candidate : candidates) {
            exists = true;
            for (const Point &p : points) {
                if (points.count(candidate - p) == 0) {
                    exists = false;
                    break;
                }
            }
            if (exists) break;
        }
        printf("%s\n", exists ? "yes" : "no");
    }
    
    return 0;
}