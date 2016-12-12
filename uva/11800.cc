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

inline double D(const Point &P, const Point &Q, const Point &R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

inline bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
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
};

double getAngle(const Point &p, const Point &p1, const Point &p2)
{
    double X = p.distTo(p1);
    double Y = p.distTo(p2);
    double Z = p1.distTo(p2);
    
    return acos((X*X + Y*Y - Z*Z) / (2 * X * Y));
}

bool isSquare(double a1, double a2, double a3, double a4, double A, double B, double C, double D)
{
    return equals(A,B) && equals(B,C) && equals(C,D) && equals(a1,a2) && equals(a2,a3) && equals(a3,a4) && equals(a1, PI/2.0);
}

bool isRectangle(double a1, double a2, double a3, double a4, double A, double B, double C, double D)
{
    return equals(A,C) && equals(B,D) && equals(a1,a2) && equals(a2,a3) && equals(a3,a4) && equals(a1, PI/2.0);
}

bool isRhombus(double a1, double a2, double a3, double a4, double A, double B, double C, double D)
{
    return equals(A,B) && equals(B,C) && equals(C,D) && !equals(a1,PI/2.0) && !equals(a2,PI/2.0) && !equals(a3,PI/2.0) && !equals(a4, PI/2.0);
}

bool isParallelogram(double a1, double a2, double a3, double a4, double A, double B, double C, double D)
{
    return equals(A,C) && equals(B,D) && !equals(a1,PI/2.0) && !equals(a2,PI/2.0) && !equals(a3,PI/2.0) && !equals(a4, PI/2.0);
}

bool isTrapezium(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
{
    Line l1(p1, p2);
    Line l2(p2, p3);
    Line l3(p3, p4);
    Line l4(p4, p1);
    
    pair<int, Point> int1 = l1.intersection(l3);
    pair<int, Point> int2 = l2.intersection(l4);
    
    return (int1.first == 0 && int2.first != 0) || (int1.first != 0 && int2.first == 0);
}

enum {SQUARE, RECTANGLE, RHOMBUS, PARAL, TRAP, ORD};

int solve(vector<Point> &points)
{
    // p1 -> p2,p4
    // p2 -> p3,p1
    // p3 -> p4,p2
    // p4 -> p1,p3
    
    Point p1 = points[0];
    Point p2 = points[1];
    Point p3 = points[2];
    Point p4 = points[3];
    
    double p1a = getAngle(p1, p2, p4);
    double p2a = getAngle(p2, p1, p3);
    double p3a = getAngle(p3, p2, p4);
    double p4a = getAngle(p4, p1, p3);
    
    double A = p1.distTo(p2);
    double B = p2.distTo(p3);
    double C = p3.distTo(p4);
    double D = p4.distTo(p1);
    
    if (isSquare(p1a, p2a, p3a, p4a, A, B, C, D)) {
        return SQUARE;
    } else if (isRectangle(p1a, p2a, p3a, p4a, A, B, C, D)) {
        return RECTANGLE;
    } else if (isRhombus(p1a, p2a, p3a, p4a, A, B, C, D)) {
        return RHOMBUS;
    } else if (isParallelogram(p1a, p2a, p3a, p4a, A, B, C, D)) {
        return PARAL;
    } else if (isTrapezium(p1, p2, p3, p4)) {
        return TRAP;
    } else {
        return ORD;
    }
}

vector<Point> convexHull(vector<Point> &P)
{
    sort(P.begin(), P.end());
    
    vector<Point> L;
    for (const Point &p : P) {
        while (L.size() >= 2 && D(L[L.size() - 2], L[L.size() - 1], p) < 0) L.pop_back();
        L.push_back(p);
    }
    
    vector<Point> U;
    for (auto it = P.rbegin(); it != P.rend(); it++) {
        const Point &p = *it;
        while (U.size() >= 2 && D(U[U.size() - 2], U[U.size() - 1], p) < 0) U.pop_back();
        U.push_back(p);
    }
    
    L.pop_back();
    U.pop_back();
    
    L.reserve(L.size() + U.size());
    L.insert(L.end(), U.begin(), U.end());
    
    return L;
}

int main()
{
    int tc = 1;
    int t;
    cin >> t;
    
    while (t--) {        
        Point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        vector<Point> ps = {p1,p2,p3,p4};
        vector<Point> points = convexHull(ps);
        int classification = points.size() == 4 ? solve(points) : ORD;
        
        printf("Case %d: ", tc++);
        switch (classification) {
            case SQUARE:
                printf("Square");
            break;
            case RECTANGLE:
                printf("Rectangle");
            break;
            case RHOMBUS:
                printf("Rhombus");
            break;
            case PARAL:
                printf("Parallelogram");
            break;
            case TRAP:
                printf("Trapezium");
            break;
            default:
                printf("Ordinary Quadrilateral");
        }
        printf("\n");     
    }
    
    return 0;
}
