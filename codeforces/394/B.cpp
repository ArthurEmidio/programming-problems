#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, L;
    scanf("%d %d", &n, &L);

    vector<int> u(n), v(n);
    for (int i = 0; i < n; i++) scanf("%d", &u[i]);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    vector<int> d1(n), d2(n);
    for (int i = 1; i < n; i++) d1[i-1] = u[i] - u[i-1];
    d1[n-1] = (u[0] + L) - u[n-1];
    for (int i = 1; i < n; i++) d2[i-1] = v[i] - v[i-1];
    d2[n-1] = (v[0] + L) - v[n-1];

    for (int i = 0; i < n; i++) d1.push_back(d1[i]);
    for (int i = 0; i < n; i++) d2.push_back(d2[i]);

    bool ans = false;
    for (int i = 0; i < n && !ans; i++) {
        ans = true;
        for (int j = i; j < n+i; j++) if (d1[j] != d2[j-i]) ans = false;
    }

    printf("%s\n", ans ? "YES" : "NO");

    return 0;
}
