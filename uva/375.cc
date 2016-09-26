#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.141592653589793

int main()
{    
    int t;
    scanf("%d", &t);
    
    while (t--) {
        double B, H;
        scanf("%lf %lf", &B, &H);
        
        double radius = 0;
        double length = 0;
        
        for (;;) {
            double C = hypot(H, B/2);
            radius = (B * H)/(B + 2*C);
            if (radius < 1e-6) break;
            
            length += radius;
            double h = 2 * radius;
            double b = (B * h) / H;
            
            H = H - h;
            B = B - b;
        }
        
        printf("%13f\n", 2 * PI * length);
        if (t > 0) printf("\n");    
    }
    
    return 0;
}
