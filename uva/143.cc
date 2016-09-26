#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

inline bool equals(double a, double b)
{
    return fabs(a - b) < EPS;
}

inline double getArea(double x0, double y0, double x1, double y1, double x2, double y2)
{   
    return fabs((x0*y1 + y0*x2 + x1*y2) - (x2*y1 + y2*x0 + x1*y0));
}

int main()
{
    for (;;) {
        double x[3], y[3];
        scanf("%lf %lf %lf %lf %lf %lf", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
        if (!x[0] && !x[1] && !x[2] && !y[0] && !y[1] && !y[2]) break;
        
        double area = getArea(x[0], y[0], x[1], y[1], x[2], y[2]);
                
        int minX = ceil(min(min(x[0], x[1]), x[2]));
        int minY = ceil(min(min(y[0], y[1]), y[2]));
        int maxX = max(max(x[0], x[1]), x[2]);
        int maxY = max(max(y[0], y[1]), y[2]);
        
        if (equals(minX, 0)) minX = 1;
        if (equals(minX, 100)) minX = 99;
        if (equals(maxX, 0)) maxX = 1;
        if (equals(maxX, 100)) maxX = 99;
        
        if (equals(minY, 0)) minY = 1;
        if (equals(minY, 100)) minY = 99;
        if (equals(maxY, 0)) maxY = 1;
        if (equals(maxY, 100)) maxY = 99;
        
        int count = 0;
        for (int i = minX; i <= maxX; i++) {
            for (int j = minY; j <= maxY; j++) {
                double area1 = getArea(i, j, x[0], y[0], x[1], y[1]);
                double area2 = getArea(i, j, x[0], y[0], x[2], y[2]);
                double area3 = getArea(i, j, x[1], y[1], x[2], y[2]);
                if (equals(area1 + area2 + area3, area)) count++;
            }
        }
        
        printf("%4d\n", count);
    }
    
    return 0;
}
