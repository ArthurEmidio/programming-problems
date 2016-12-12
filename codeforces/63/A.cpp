#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int forces[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            forces[j] += x;
        }
    }
    
    bool eq = !forces[0] && !forces[1] && !forces[2];
    printf("%s\n", eq ? "YES" : "NO");
       
    return 0;
}