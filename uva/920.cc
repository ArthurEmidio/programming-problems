#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

int main()
{
    int C;
    cin >> C;
    
    while (C--) {
        int N;
        cin >> N;
        
        vector<Point> points(N);        
        for (int i = 0; i < N; i++) {
            cin >> points[N - i - 1].x >> points[N - i - 1].y;
        }
        sort(points.begin(), points.end(), [](const Point &p1, const Point &p2) {
            return p1.x > p2.x;
        });
        
        Point highest = points[0];
        double length = 0;
        
        for (int i = 1; i < N; i++) {
            Point &p = points[i];
            
            if (highest.y < p.y) {
                double D = p.distTo(points[i - 1]);
                double h = p.y - highest.y;
                double H = p.y - points[i - 1].y;
                double d = (D * h) / H;
                length += d;
                highest = p;
            }
        }
        printf("%.2f\n", length);
    }
    
    return 0;
}
