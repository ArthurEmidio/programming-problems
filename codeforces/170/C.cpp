#include <bits/stdc++.h>

using namespace std;

vector<int> uf;

int ans;

int find(int x)
{
    return uf[x] == x ? x : uf[x] = find(uf[x]);
}

void merge(int x, int y)
{
    if (find(x) != find(y)) {
        uf[find(x)] = find(y);
        ans--;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    ans = n;
    
    for (int i = 0; i < n; i++) uf.push_back(i);
    
    bool tmp = false;
    vector<int> langReps(m+1, -1);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        
        if (k) tmp = true;
        
        while (k--) {
            int a;
            cin >> a;
            if (langReps[a] == -1) langReps[a] = i;
            else merge(i, langReps[a]);
        }
    }
    
    cout << (tmp ? (ans-1) : n) << endl;
    
    return 0;
}
