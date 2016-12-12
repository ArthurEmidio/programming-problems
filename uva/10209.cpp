#include <bits/stdc++.h>

using namespace std;

int main()
{
    double PI = 2*acos(0);
    
    double a;
    while (cin >> a) {
        double Z = a*a*(1 - (sqrt(3)/4.0) - (PI/6.0));
        double Y = a*a - a*a*(PI/4.0) - 2*Z;
        double X = a*a - 4*Y - 4*Z;
        
        printf("%.3f %.3f %.3f\n", X, 4*Y, 4*Z);
    }
    
    return 0;
}