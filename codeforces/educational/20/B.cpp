#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    vector<long long> left(n, 0), right(n, 0);
    if (v[0]) left[0] = oo;
    if (v[n - 1]) right[n - 1] = oo;

    for (int i = 1; i < n; i++) {
        int j = n - i - 1;
        if (v[i]) left[i] = left[i - 1] + 1;
        if (v[j]) right[j] = right[j + 1] + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%lld ", min(left[i], right[i]));
    }
    printf("\n");

    return 0;
}
