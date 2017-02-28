#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)
#define N 200005

typedef long long ll;
typedef vector<int> vi;

int uf[N];

int find(int x)
{
    return (x == uf[x]) ? x : (uf[x] = find(uf[x]));
}

void merge(int x, int y)
{
    int px = find(x), py = find(y);
    if (px != py) uf[px] = py;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 0; i < n; i++) uf[i] = i, uf[i+n] = i+n;

    char s1[25], s2[25];
    map<string, int> words;
    for (int i = 0; i < n; i++) {
        scanf("%s", s1);
        words[s1] = i;
    }

    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d %s %s", &t, s1, s2);
        int x1 = words[s1], y1 = words[s2];
        int x2 = x1+n, y2 = y1+n;

        bool ans = false;
        if (t == 2) {
            if (find(x1) != find(y1) && find(x2) != find(y2)) {
                merge(x1, y2);
                merge(x2, y1);
                ans = true;
            }
        } else {
            if (find(x1) != find(y2) && find(x2) != find(y1)) {
                merge(x1, y1);
                merge(x2, y2);
                ans = true;
            }
        }

        printf("%s\n", ans ? "YES" : "NO");
    }

    for (int i = 0; i < q; i++) {
        scanf("%s %s", s1, s2);
        int x1 = words[s1], y1 = words[s2];
        int x2 = x1+n, y2 = y1+n;

        int ans;
        if (find(x1) == find(x2) || find(x2) == find(y2)) ans = 1;
        else if (find(x1) == find(y2) || find(x2) == find(y1)) ans = 2;
        else ans = 3;

        printf("%d\n", ans);
    }

    return 0;
}
