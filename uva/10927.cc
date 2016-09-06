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
        return pair<double, double>(x, y) < pair<double, double>(p.x, p.y);
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
    ios_base::sync_with_stdio(false);
    
    for (int t = 1; ; t++) {
        int n;
        scanf("%d", &n);
        if (!n) break;
        
        map<Line, vector<pair<int, Point>>> lines;
        
        for (int i = 0; i < n; i++) {
            Point p;
            int height;
            scanf("%lf %lf %d", &p.x, &p.y, &height);
            Line l(p, Point(0, 0));
            lines[l].push_back(make_pair(height, p));
        }

        vector<Point> invisible;
        for (const auto &line : lines) {
            const Line &l = line.first;
            auto &poles = line.second;
            
            int prevHeightIdx = 0;
            for (int i = 0; i < poles.size(); i++) {
                auto &pole = poles[i];
                Segment s(pole.second, Point(0,0));
                
                for (int j = 0; j < poles.size(); j++) {
                    if (i == j) continue;
                    auto &otherPole = poles[j];
                    if (otherPole.first >= pole.first && s.contains(otherPole.second)) {
                        invisible.push_back(pole.second);
                        break;
                    }
                }
            }
        }

        sort(invisible.begin(), invisible.end(), [](const Point &p1, const Point &p2) {
            if (p1.x < p2.x) {
                return true;
            } else if (p1.x > p2.x) {
                return false;
            } else {
                return p1.y < p2.y;
            }
        });

        printf("Data set %d:\n", t);
        if (invisible.empty()) {
            printf("All the lights are visible.\n");
        } else {
            printf("Some lights are not visible:\n");
            for (int i = 0; i < invisible.size(); i++) {
                printf("x = %.0f, y = %.0f", invisible[i].x, invisible[i].y);
                printf("%c\n", (i == invisible.size() - 1) ? '.' : ';');
            }
        }
    }
    
    return 0;
}
