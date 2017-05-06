#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    set<int> holes;
    for (int i = 0; i < m; i++) {
        int h;
        scanf("%d", &h);
        holes.insert(h);
    }

    int ans = 1;
    bool fell = holes.count(1);
    for (int i = 0; i < k; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (!fell && (ans == u || ans == v)) {
            if (ans == u) ans = v;
            else if (ans == v) ans = u;
            if (holes.count(ans)) fell = true;
        }
    }

    cout << ans << endl;

    return 0;
}
