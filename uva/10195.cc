#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.141592653589793

int main()
{    
    for (;;) {
        double a, b, c;
        cin >> a;
        if (cin.eof()) break;
        cin >> b >> c;
        
        double perimeter = a + b + c;
        double s = perimeter / 2.0;
        double area = sqrt(s*(s - a)*(s - b)*(s - c));
        double radius = (2 * area) / perimeter;
        printf("The radius of the round table is: %.3f\n", isnan(radius) ? 0 : radius);
    }
    
    return 0;
}
