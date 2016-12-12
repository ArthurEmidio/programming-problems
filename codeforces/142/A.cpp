#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;
    
    map<int, int> attacks;    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        attacks[x] += y;
    }
    
    bool ans = true;
    for (auto it = attacks.begin(); it != attacks.end(); it++) {
        if (s <= it->first) {
            ans = false;
            break;
        }
        s += it->second;
    }
    
    printf("%s\n", ans ? "YES" : "NO");
    
    return 0;
}