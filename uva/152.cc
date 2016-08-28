#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point
{
    ll x;
    ll y;
    ll z;
    
    Point(ll _x, ll _y, ll _z) : x(_x), y(_y), z(_z) { }
    
    inline double distTo(const Point &p) const
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z));
    }
};

int main()
{
    vector<Point> points;
    for (;;) {
        ll x, y, z;
        cin >> x >> y >> z;
        if (x == 0 && y == 0 & z == 0) break;
        points.push_back(Point(x, y, z));
    }
    
    vector<int> hist(10, 0);
    for (int i = 0; i < points.size(); i++) {
        const Point &p = points[i];
        double minDist = numeric_limits<double>::infinity();
        for (int j = 0; j < points.size(); j++) {
            if (i != j) {
                minDist = min(p.distTo(points[j]), minDist);
            }
        }
        
        if (minDist < 10.0) hist[floor(minDist)]++;
    }
    
    for (int i = 0; i < hist.size(); i++) {
        printf("% 4d", hist[i]);
    }
    cout << endl;
    
    return 0;
}
