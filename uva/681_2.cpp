#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793
#define EPS 1e-4

typedef long long ll;

class Point {
public:
    ll x;
    ll y;

    Point(ll xv = 0, ll yv = 0) : x(xv), y(yv) {}

    bool operator<(const Point& P) const
    {
        return x == P.x ? y < P.y : x < P.x;
    }
    
    double distance(const Point &p) const
    {
        return hypot(p.x - x, p.y - y);
    }
    
    bool operator==(const Point &p) const
    {
        return p.x == x && p.y == y;
    }
};

ll D(const Point& P, const Point& Q, const Point& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

bool equals(double x, double y)
{
    return fabs(x-y) < EPS;
}

Point pivot(vector<Point>& P)
{
    size_t idx = 0;

    for (size_t i = 1; i < P.size(); ++i)
        if (P[i].y < P[idx].y or (equals(P[i].y, P[idx].y) and P[i].x > P[idx].x))
            idx = i;

    swap(P[0], P[idx]);

    return P[0];
}

void sort_by_angle(vector<Point>& P)
{
    auto P0 = pivot(P);

    sort(P.begin() + 1, P.end(), [&](const Point& A, const Point& B)
        {
            if (equals(D(P0, A, B), 0))
                return A.distance(P0) < B.distance(P0);

            auto dx = A.x - P0.x;
            auto dy = A.y - P0.y;
            auto alfa = atan2(dy, dx);

            dx = B.x - P0.x;
            dy = B.y - P0.y;
            auto beta = atan2(dy, dx);

            return alfa < beta;
        }
    );
}

vector<Point> convexHull(const vector<Point>& points)
{
    vector<Point> P(points);
    auto n = P.size();

    // Corner case: com 3 vértices ou menos, P é o próprio convex hull
    if (n <= 3)
        return points;

    sort_by_angle(P);

    vector<Point> s;
    s.push_back(P[n - 1]);
    s.push_back(P[0]);
    s.push_back(P[1]);

    size_t i = 2;

    while (i < n)
    {
        auto j = s.size() - 1;

        if (D(s[j - 1], s[j], P[i]) > 0)
            s.push_back(P[i++]);
        else
            s.pop_back();
    }

    if (s.front() == s.back())
        s.pop_back();

    return s;
}

int main()
{
    int n;
    cin >> n;
    printf("%d\n", n);
    
    while (n--) {
        int m;
        cin >> m;
        
        vector<Point> vertices(m);
        for (int i = 0; i < m; i++) {
            cin >> vertices[i].x >> vertices[i].y;
        }
        if (n > 0) {
            int usl;
            cin >> usl;
        }
        
        vector<Point> ch = convexHull(vertices);
        printf("%lu\n", ch.size() + 1);
        
        int start = 0;
        for (int i = 0; i < ch.size(); i++) {
            if (ch[i].y < ch[start].y || (ch[i].y == ch[start].y && ch[i].x < ch[start].x)) {
                start = i;
            }
        }
        
        for (int i = 0; i < ch.size(); i++) {
            int idx = (start + i) % ch.size();
            printf("%lld %lld\n", ch[idx].x, ch[idx].y);
        }
        printf("%lld %lld\n", ch[start].x, ch[start].y);
        if (n > 0) printf("-1\n");
    }
    
    return 0;
}
