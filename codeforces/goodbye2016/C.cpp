#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define ff first
#define ss second

typedef pair<int,int> ii;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    
    vector<ii> data(n);
    for (int i = 0; i < n; i++) scanf("%d %d", &data[i].ff, &data[i].ss);
    
    int mi = -oo, ma = oo;
    if (data[0].ss == 1) mi = 1900;
    else ma = 1899;
    
    int acc = data[0].ff;
    bool possible = true;    
    for (int i = 1; i < n; i++) {        
        if (data[i].ss == 1) mi = max(mi, 1900 - acc);
        else ma = min(ma, 1899 - acc);
        if (mi > ma) possible = false;
        acc += data[i].ff;
    }
    
    if (possible) {
        if (ma == oo) printf("Infinity\n");
        else printf("%d\n", ma + acc);
    } else printf("Impossible\n");
    
    return 0;
}
