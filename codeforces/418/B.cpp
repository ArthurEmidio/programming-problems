#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> a(n), b(n), v(n);
    set<int> seen;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), seen.insert(i + 1);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    int indices[2], m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) indices[m++] = i;
        else v[i] = a[i], seen.erase(a[i]);
    }

    if (seen.size() == 1) {
        v[indices[0]] = *seen.begin();
    } else {
        int x = indices[0], y = indices[1];
        if (seen.count(a[x]) && seen.count(b[y])) v[x] = a[x], v[y] = b[y];
        else v[x] = b[x], v[y] = a[y];
    }

    for (int x : v) printf("%d ", x);
    printf("\n");

    return 0;
}
