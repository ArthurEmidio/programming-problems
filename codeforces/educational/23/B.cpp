#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());

    map<int, int> m;
    for (int i = 0; i < 3; i++) m[v[i]] = 0;
    for (int x : v) if (m.count(x)) m[x]++;

    long long ans = 1;
    for (int i = 0; i < 3; i++) ans *= m[v[i]]--;
    if (m.size() == 1) ans /= 6;
    else if (m.size() == 2) ans /= 2;

    cout << ans << endl;

    return 0;
}
