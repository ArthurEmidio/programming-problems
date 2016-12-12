#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)
#define oo numeric_limits<ll>::max()

vector<ll> votes;

ll rsq(int L, int R)
{
    return votes[R + 1] - votes[L];
}

int main()
{   
    int n, k;
    scanf("%d %d", &n, &k);

    votes.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &votes[i]);
        votes[i] += votes[i-1];
    }

    vector<ll> rangeSums;
    for (int i = 0; i+k-1 < n; i++) {
        rangeSums.push_back(rsq(i, i+k-1));
    }
    
    vector<pair<ll,ll>> maxRanges(rangeSums.size() + 1, mp(0,0));
    for (ll i = rangeSums.size() - 1; i >= 0; i--) {
        maxRanges[i] = rangeSums[i] >= maxRanges[i+1].ff ? mp(rangeSums[i], i) : maxRanges[i+1];      
    }

    pair<ll,ll> ans;
    ll best = -oo;
    for (ll i = 0; i+k < maxRanges.size(); i++) {
        ll tmp = rangeSums[i] + maxRanges[i+k].ff;
        if (tmp > best) {
            best = tmp;
            ans.ff = i + 1;
            ans.ss = maxRanges[i+k].ss + 1;
        }
    }
    
    cout << ans.ff << " " << ans.ss << endl;
    
    return 0;
}
