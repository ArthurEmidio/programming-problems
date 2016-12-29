#include <bits/stdc++.h>

using namespace std;

int digits[10] = {};

void f(int a, int b, int c, int d, int e, int g)
{
    if (digits[a]) digits[a]--;
    else if (digits[b]) digits[b]--;
    else if (digits[c]) digits[c]--;
    else if (digits[d] >= 2) digits[d] -= 2;
    else if (digits[e] >= 2) digits[e] -= 2;
    else if (digits[g] >= 2) digits[g] -= 2;
    else for (int i = 1; i <= 8; i++) if (i%3 != 0) digits[i] = 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        digits[d]++;
    }
    
    if (!digits[0]) {
        printf("-1\n");
    } else {
        digits[0]--;
        
        int sum = 0;
        for (int i = 1; i <= 8; i++) if (i%3 != 0) sum += i*digits[i];
        if (sum % 3 == 1) f(1,4,7,2,5,8);
        else if (sum % 3 == 2) f(2,5,8,1,4,7);
        
        bool only0 = true;
        for (int i = 1; i <= 9; i++) if (digits[i]) only0 = false;
        
        if (!only0) {
            for (int i = 9; i >= 0; i--) {
                for (int j = 0; j < digits[i]; j++) printf("%d", i);
            }
        }
        printf("0\n");
    }
    
    return 0;
}