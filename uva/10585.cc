#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> Point;

inline Point operator+(const Point &p1, const Point &p2)
{
    return Point(p1.first + p2.first, p1.second + p2.second);
}

inline Point operator-(const Point &p1, const Point &p2)
{
    return Point(p1.first - p2.first, p1.second - p2.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int c;
    scanf("%d", &c);
    
    for (int t = 0; t < c; t++) {
        int n;
        scanf("%d", &n);
        
        set<Point> points;
        for (int i = 0; i < n; i++) {
            Point p;
            scanf("%lld %lld", &p.first, &p.second);
            points.insert(p);
        }
        
        bool valid;
        Point first = *(points.begin());
        for (const Point &p : points) {
            Point s = first + p; // 2 * s
            valid = true;
            for (const Point &p2 : points) {
                if (points.count(s - p2) == 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) break;
        }
        
        printf("%s\n", valid ? "yes" : "no");
    }
    
    return 0;
}
