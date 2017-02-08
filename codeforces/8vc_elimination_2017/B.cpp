#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    set<string> pbs;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        pbs.insert(s);
    }
    
    int mutual = 0;
    int eb = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (pbs.count(s)) {
            pbs.erase(s);
            mutual++;
        } else eb++;
    }
    int pb = pbs.size();
    
    bool turn = true;
    bool ans = true;
    for (;;) {
        if (turn) {
            if (!pb && !mutual) {
                ans = false;
                break;
            }
            if (mutual) mutual--;
            else pb--;            
        } else {
            if (!eb && !mutual) break;
            if (mutual) mutual--;
            else eb--;
        }
        turn = !turn;
    }
    
    printf("%s\n", ans ? "YES" : "NO");
    
    return 0;
}