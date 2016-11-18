#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-13

bool equals(double x, double y)
{
    return fabs(x - y) < EPS;
}

int main()
{    
    for (;;) {
        int n, a;
        scanf("%d %d", &n, &a);
        if (!n) break;
        
        int m = 0;
        for (int i = 0; i < n; i++) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            
            double h1 = hypot(x, y);
            double h2 = hypot(a - x, y);
            double h3 = hypot(a - x, a - y);
            double h4 = hypot(x, a - y);

            // if (h1 <= a && h2 <= a && h3 <= a && h4 <= a) ++m;
            
            if ((h1 < a || equals(h1, a)) && (h2 < a || equals(h2, a)) &&
                (h3 < a || equals(h3, a)) && (h4 < a || equals(h4, a))) m++;
        }

        printf("%.5f\n", m * a * a / (double)n);
    }
    
    return 0;
}
