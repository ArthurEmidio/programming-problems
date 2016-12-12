#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793
#define EPS 1e-7

typedef long long ll;

int main()
{
    for (;;) {
        int L, C, R1, R2;
        cin >> L >> C >> R1 >> R2;
        if (!L && !C && !R1 && !R2) break;
        
        bool ans = 2*R1 <= L && 2*R1 <= C && 2*R2 <= L && 2*R2 <= C;
        ans = ans && hypot(R1 - (L-R2), R1 - (C - R2)) >= R1+R2;
        
        printf("%c\n", ans ? 'S' : 'N');
    }
    
    return 0;
}

// (R1,R1) ; (L-R2, C-R2)