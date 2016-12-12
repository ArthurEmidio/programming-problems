#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> lucky = {4,7,44,47,74,77,444,474,477,744,747,774,777};
    bool ans = false;
    for (int x : lucky) {
        if (n % x == 0) {
            ans = true;
            break;
        }
    }
    
    printf("%s\n", ans ? "YES" : "NO");
    
    return 0;
}