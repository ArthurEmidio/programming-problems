#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    for (int i = 0; i < n/2; i++) {
        if (i % 2 == 0) swap(v[i], v[n-i-1]);
    }

    for (int x : v) printf("%d ", x);
    printf("\n");

    return 0;
}
