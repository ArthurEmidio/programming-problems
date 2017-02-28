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

int n;
int v1[1005];
multiset<int> v2;

int solve1()
{
    multiset<int> v22 = v2;
    for (int i = 0; i < n; i++) {
        auto it = v22.lower_bound(v1[i]);
        if (it == v22.end()) return n - i;
        v22.erase(it);
    }

    return 0;
}

int solve2()
{
    multiset<int> v22 = v2;
    for (int i = 0; i < n; i++) {
        auto it = v22.upper_bound(v1[i]);
        if (it == v22.end()) return i;
        v22.erase(it);
    }

    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++) v1[i] = (s1[i] - '0'), v2.insert(s2[i] - '0');
    sort(v1, v1+n);

    printf("%d\n%d\n", solve1(), solve2());

    return 0;
}
