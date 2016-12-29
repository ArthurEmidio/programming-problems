#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int M[n], R[n];
    for (int i = 0; i < n; i++) scanf("%d", &M[i]);
    for (int i = 0; i < n; i++) scanf("%d", &R[i]);
    
    int cnt = 0;
    for (int D = 0; D < 100000; D++) {
        for (int i = 0; i < n; i++) {
            if (D % M[i] == R[i]) {
                cnt++;
                break;
            }
        }
    }
    
    printf("%.6f\n", cnt/100000.00);
    
    return 0;
}