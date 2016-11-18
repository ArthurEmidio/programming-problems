#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846
#define LSOne(i) (i & (-i))

typedef long long ll;
typedef vector<int> vi;

vector<ll> acc;

inline ll rsq(int a, int b)
{
    return a > b ? 0 : acc[b] - acc[a - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    
    acc.push_back(0);
    for (int i = 1; i <= n; i++) {
        ll v;
        scanf("%lld", &v);
        acc.push_back(acc[i-1] + v);
    }
    
    multiset<ll> sums;
    sums.insert(rsq(1, n));
    
    set<int> cuts;
    for (int i = 0; i < n; i++) {
        int cut;
        scanf("%d", &cut);
        
        auto it = cuts.insert(cut).first;
        int prevIdx = (it == cuts.begin()) ? 1 : (*prev(it) + 1);
        int nextIdx = (it == prev(cuts.end())) ? n : (*next(it) - 1);
        
        ll old = rsq(prevIdx, nextIdx);
        auto itOld = sums.find(old);
        sums.erase(itOld);
                
        ll prevSum = rsq(prevIdx, cut - 1);
        ll nextSum = rsq(cut + 1, nextIdx);
                        
        sums.insert(prevSum);
        sums.insert(nextSum);
                                
        if (!sums.empty()) printf("%lld\n", *prev(sums.end()));
        else printf("0\n");        
    }
    
    return 0;
}
