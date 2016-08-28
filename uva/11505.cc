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
    
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        
        Point pos;
        double angle = 0;
        
        for (int j = 0; j < n; j++) {
            char com[3];
            int num;
            scanf("%s %d", com, &num);
            
            if (strcmp(com, "fd") == 0) {
                pos.x += sin(angle) * num;
                pos.y += cos(angle) * num;
            } else if (strcmp(com, "bk") == 0) {
                pos.x -= sin(angle) * num;
                pos.y -= cos(angle) * num;
            } else if (strcmp(com, "lt") == 0) {
                angle += (PI * num) / 180.0;
            } else {
                angle -= (PI * num) / 180.0;
            }
        }
        
        printf("%.0f\n", round(pos.distTo(Point(0,0))));
    }
    
    return 0;
}
