#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793

typedef long long ll;

struct Point
{
    double x;
    double y;
    
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) { }
    
    inline double distTo(const Point &p) const
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    
    for (;;) {
        int n, T;
        if (scanf("%d%d", &n, &T) == EOF) break;
        
        const double constant = 2.0 * PI * T;
        Point prevPoint;
        for (int i = 0; i < n; i++) {
            int r, t;
            scanf("%d %d", &r, &t);
            
            double angle = constant / t;
            double x = r * cos(angle) + prevPoint.x;
            double y = r * sin(angle) + prevPoint.y;
            
            prevPoint = Point(x, y);
            printf("%.4f", prevPoint.distTo(Point(0,0)));
            if (i != n - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
