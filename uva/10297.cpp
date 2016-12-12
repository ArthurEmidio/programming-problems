#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793

int main()
{
    for (;;) {
        int D, V;
        cin >> D >> V;
        if (!D && !V) break;        
        printf("%.3f\n", cbrt(D*D*D - 6*V/PI));
    }
    
    return 0;
}
