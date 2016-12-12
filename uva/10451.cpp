#include <bits/stdc++.h>

#define PI 2*acos(0)

using namespace std;

int main()
{
    int tc = 1;
    for (;;) {
        int n;
        double A;
        cin >> n >> A;
        if (n < 3) break;
        
        double R = sqrt((2*A) / (n * sin(2*PI/n)));
        double r = sqrt(A / (n * tan(PI/n)));
        
        double bigArea = PI * R * R;
        double smallArea = PI * r * r;
        
        double spectators = bigArea - A;
        double officials = A - smallArea;
        
        printf("Case %d: %.5f %.5f\n", tc++, spectators, officials);
    }
    
    return 0;
}