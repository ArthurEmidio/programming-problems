#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;

int maxLevel(int node, int level)
{
    int ans = 0;
    for (int child : tree[node]) {
        ans = max(ans, maxLevel(child, level + 1));
    }
    return 1 + ans;
}

int main()
{
    int n;
    cin >> n;
    
    tree.assign(n, vector<int>());
    vector<int> roots;
    
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        
        if (p != -2) tree[p].push_back(i);
        else roots.push_back(i);
    }
    
    int ans = 1;
    for (int root : roots) {
        ans = max(ans, maxLevel(root, 1));
    }
    
    cout << ans << endl;
    
    return 0;
}