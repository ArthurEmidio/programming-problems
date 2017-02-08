#include <bits/stdc++.h>

using namespace std;

vector<int> uf;

int find(int u)
{
    return (uf[u] == u) ? u : (uf[u] = find(uf[u]));
}

void join(int u, int v)
{
    uf[find(u)] = find(v);
}

int main()
{   
    int n;
    cin >> n;
    
    uf.assign(n, 0);
    for (int i = 0; i < n; i++) uf[i] = i;
    
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        join(i, p-1);
    }
    
    set<int> reps;
    for (int i = 0; i < n; i++) reps.insert(find(i));
    printf("%lu\n", reps.size());
    
    return 0;
}