#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;

ll n, m, k;

ll gauss(ll n)
{
    if (n <= 0) return 0;
    return n*(n+1)/2;
}

bool test(ll x)
{
    ll ans = x;
    ans += (gauss(x) - gauss(x - k)) + (gauss(x) - gauss(x - (n-k+1)));
    if (k > x) ans += k - x;
    if (n-k+1 > x) ans += n-k-x+1;
    return (ans - 2*x) <= m;
}

int find(ll left, ll right)
{
    if (left > right) return -1;
    ll mid = (left + right) / 2;
    if (!test(mid)) return find(left, mid-1);
    ll tmp = find(mid+1, right);
    return tmp < 0 ? mid : tmp;
}

int main()
{
    cin >> n >> m >> k;
    cout << find(1, m) << endl;
    return 0;
}
