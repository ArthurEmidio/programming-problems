#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0)

int main()
{
    int N;
    cin >> N;
    while (N--) {
        double D, L;
        cin >> D >> L;
        
        double x = sqrt(L*L - D*D)/2.0;
        printf("%.3f\n", x * (L/2.0) * PI);
    }
    
    return 0;
}
