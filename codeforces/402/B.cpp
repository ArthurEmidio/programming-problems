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

int main()
{
    ios_base::sync_with_stdio(false);

    string n;
    int k;
    cin >> n >> k;

    int ans = 0;
    for (int i = n.size() - 1; i >= 0 && k; i--) {
        if (n[i] == '0') k--;
        else ans++;
    }

    printf("%d\n", k ? (n.size() - 1) : ans);

    return 0;
}
