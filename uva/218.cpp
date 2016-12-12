#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793
#define EPS 1e-4

typedef long long ll;
using Point = pair<double, double>;

double D(const Point &P, const Point &Q, const Point &R)
{
    return (P.first * Q.second + P.second * R.first + Q.first * R.second) - (R.first * Q.second + R.second * P.first + Q.first * P.second);
}

vector<Point> convexHull(vector<Point> &P)
{
    sort(P.begin(), P.end());
    
    vector<Point> L;
    for (const Point &p : P) {
        while (L.size() >= 2 && D(L[L.size() - 2], L[L.size() - 1], p) > 0) L.pop_back();
        L.push_back(p);
    }
    
    vector<Point> U;
    for (auto it = P.rbegin(); it != P.rend(); it++) {
        const Point &p = *it;
        while (U.size() >= 2 && D(U[U.size() - 2], U[U.size() - 1], p) > 0) U.pop_back();
        U.push_back(p);
    }
    
    L.pop_back();
    U.pop_back();
    
    L.reserve(L.size() + U.size());
    L.insert(L.end(), U.begin(), U.end());
    L.push_back(L[0]);
    
    return L;
}

class Polygon
{
public:
    vector<Point> vertices;
    int n;
    
    Polygon(const vector<Point> &_vertices) : vertices(_vertices), n(_vertices.size())
    {
        vertices.push_back(vertices[0]);
    }

    double area() const
    {
        double a = 0;
        for (int i = 0; i < n; i++) {
            a += vertices[i].first * vertices[i + 1].second;
            a -= vertices[i+1].first * vertices[i].second;
        }
        return 0.5 * fabs(a);
    }
};

double dist(const Point &p1, const Point &p2)
{
    return hypot(p1.first - p2.first, p1.second - p2.second);
}

int main()
{
    int tc = 1;
    
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;
        
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        
        vector<Point> ch = convexHull(points);
        double perimeter = 0;
        for (int i = 1; i < ch.size(); i++) {
            perimeter += dist(ch[i - 1], ch[i]);
        }
        
        printf("Region #%d:\n", tc++);
        printf("(%.1f,%.1f)", ch[0].first, ch[0].second);
        for (int i = 1; i < ch.size(); i++) {
            printf("-(%.1f,%.1f)", ch[i].first, ch[i].second);
        }
        printf("\nPerimeter length = %.2f\n\n", perimeter);
    }
    
    return 0;
}
