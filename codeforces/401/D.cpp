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

int ans[500005];
vector<string> v;

void f(int i, int j, int k)
{
    int y = j-1;
    for (int x = j+1; x <= k; x++) {
        if (i >= v[x].size() || v[x][i] < v[x-1][i]) y = x-1;
    }

    int l = y+2;
    while (l <= k) {
        int m = l-1;
        while (l <= k && v[l][i] == v[l-1][i]) l++;
        f(i+1, m, l-1);
        l++;
    }

    while (y >= j) ans[y--] = i;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    char s[500005];
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        v.push_back(s);
        ans[i] = v[i].size();
    }

    f(0, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%s\n", v[i].substr(0, ans[i]).c_str());
    }

    return 0;
}
