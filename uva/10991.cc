#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define EPS 1e-7
#define PI 3.141592653589793

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

class Triangle
{
public:
    Point A, B, C;
    double a, b, c;
    
    Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    
    Triangle(const Point &_A, const Point &_B, const Point &_C) : A(_A), B(_B), C(_C)
    {
        a = A.distTo(B);
        b = B.distTo(C);
        c = A.distTo(C);
    }

    typedef enum {EQUILATERAL, ISOSCELES, SCALENE} Sides;
    
    Sides sidesClassification() const
    {
        if (a == b && b == c) {
            return EQUILATERAL;
        }
        
        if (a == b || a == c || b == c) {
            return ISOSCELES;
        }
        
        return SCALENE;
    }

    typedef enum {RIGHT, ACUTE, OBTUSE} Angles;
    
    Angles classifyAngles() const
    {
        double AB = acos((a*a + b*b - c*c) / (2*a*b));
        double AC = acos((a*a - b*b + c*c) / (2*a*c));
        double BC = acos((-a*a + b*b + c*c) / (2*b*c));
        
        double right = PI / 2.0;
        
        if (equals(AB, right) || equals(AC, right) || equals(BC, right)) {
            return RIGHT;
        }
        
        if (AB > right || AC > right || BC > right) {
            return OBTUSE;
        }
        
        return ACUTE;
    }

    double perimeter() const
    {
        return a + b + c;
    }
    
    double area() const
    {
        auto s = perimeter() / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    
    double area2() const
    {
        double det = (A.x*B.y + A.y*C.x + B.x*C.y) - (C.x*B.y + C.y*A.x + B.x*A.y);
        return 0.5 * fabs(det);
    }
    
    // centroid
    Point barycenter() const
    {
        auto x = (A.x + B.x + C.x) / 3.0;
        auto y = (A.y + B.y + C.y) / 3.0;
        return Point(x, y);
    }
    
    // radius of the largest circle that fits the triangle
    double inradius() const
    {
        return (2 * area()) / perimeter();
    }
    
    Point incenter() const
    {
        auto p = perimeter();
        auto x = (a*A.x + b*B.x + c*C.x) / p;
        auto y = (a*A.y + b*B.y + c*C.y) / p;
        return Point(x, y);
    }
    
    // the circle that passes by the 3 vertices of the triangle
    double circumradius() const
    {
        return (a * b * c) / (4 * area());
    }
    
    Point circumcenter() const
    {
        auto d = (A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y)) / 2.0;

        auto A2 = A.x*A.x + A.y*A.y;
        auto B2 = B.x*B.x + B.y*B.y;
        auto C2 = C.x*C.x + C.y*C.y;

        auto x = (A2*(B.y - C.y) + B2*(C.y - A.y) + C2*(A.y - B.y)) * d;
        auto y = (A2*(C.x - B.x) + B2*(A.x - C.x) + C2*(B.x - A.x)) * d;

        return Point(x, y);
    }
    
    double opositeAngle(double side) const
    {
        return asin(side / (2 * circumradius()));
    }
    
};

int main()
{
    int k;
    scanf("%d", &k);
    
    while (k--) {
        double r1, r2, r3;
        scanf("%lf %lf %lf", &r1, &r2, &r3);
        
        double a = r1 + r2;
        double b = r1 + r3;
        double c = r2 + r3;
        
        double AC = acos((a*a - b*b + c*c)/(2*a*c));
        double AB = acos((a*a + b*b - c*c)/(2*a*b));
        double BC = acos((-a*a + b*b + c*c)/(2*b*c));
        
        double area1 = (r1 * r1) * AB / 2.0;
        double area2 = (r2 * r2) * AC / 2.0;
        double area3 = (r3 * r3) * BC / 2.0;
        
        double tArea = Triangle(a, b, c).area();
        printf("%.6f\n", tArea - area1 - area2 - area3);
    }
    
    return 0;
}
