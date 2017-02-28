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

vector<int> order;

bool check(const string &s, const string &t)
{
    int i = 0;
    int n = t.size();
    for (char c : s) {
        if (t[i] == c) i++;
        if (i == n) break;
    }
    return i == n;
}

string f(const string &s, int i)
{
    string ans;
    vector<bool> can(s.size(), false);
    for (int j = 0; j < i; j++) can[order[j]-1] = true;
    for (int i = 0; i < s.size(); i++) if (can[i]) ans += s[i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    char t[200005], p[200005];
    scanf("%s %s", t, p);
    int n = strlen(t);

    order.assign(n, 0);
    for (int i = 0; i < n; i++) scanf("%d", &order[i]);
    reverse(order.begin(), order.end());

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        string sub = f(t, mid);

        if (check(sub, p)) r = mid;
        else l = mid + 1;
    }

    printf("%d\n", n - l);

    return 0;
}
