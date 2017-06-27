#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        l--, r--, x--;

        int pos = l;
        for (int i = l; i <= r; i++) {
            if (v[i] < v[x]) {
                pos++;
            }
        }

        printf("%s\n", pos == x ? "Yes" : "No");
    }

    return 0;
}
