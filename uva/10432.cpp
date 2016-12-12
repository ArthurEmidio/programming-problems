#include <bits/stdc++.h>

#define PI 3.141592653589793

using namespace std;

int main()
{
    double r, n;
    while (cin >> r >> n) {    
        double ans = 0.5 * n * r*r * sin(2.0*PI/n);
        printf("%.3f\n", ans);
    }
    
    return 0;
}