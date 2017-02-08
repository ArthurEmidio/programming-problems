#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll goal, ll end)
{
    ll begin = 0;
    ll tot = end*(end+1)/2;
    if (tot < goal) return 0;
        
    while (begin < end) {
        ll mid = (begin + end) / 2;
        ll quant = tot - (mid*(mid+1) / 2);
        if (quant > goal) begin = mid + 1;
        else if (quant < goal) end = mid - 1;
        else return mid+1;
    }
        
    if (tot - (begin * (begin+1))/2 <= goal) return begin+1;
    else return begin + 2;
}

int main()
{       
    ll n, k;
    cin >> n >> k;
    n--, k--;

    ll greatest = k, ans = 0;
    if (n < greatest) {
        if (n) ans = 1;
        n = 0;
    } else {
        ll begin = solve(n, greatest);
        if (begin) {
            ll tot = greatest*(greatest+1)/2;
            n -= tot - begin*(begin-1)/2;
            ans = (greatest - begin + 1);
            if (n && n <= greatest) ans++, n = 0;
        }
    }

    printf("%lld\n", n ? -1 : ans);
    
    return 0;
}