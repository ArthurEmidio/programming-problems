#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    vector<int> u(k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &u[i]);
    }

    sort(u.begin(), u.end(), greater<int>());

    int j = 0;
    for (int i = 0; i < k; i++) {
        while (v[j]) j++;
        v[j] = u[i];
    }

    bool ans = false;
    for (int i = 1; i < n; i++) {
        if (v[i] <= v[i-1]) ans = true;
    }

    printf("%s\n", ans ? "Yes" : "No");

    return 0;
}
