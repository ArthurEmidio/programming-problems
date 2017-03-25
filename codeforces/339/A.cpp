#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll l, r, k;
    cin >> l >> r >> k;

    ll bef = 1, curr = 1;
    bool valid = false;

    do {
        if (curr >= l) printf("%lld ", curr), valid = true;
        bef = curr;
        curr *= k;
    } while (curr <= r && bef == curr/k);

    if (!valid) printf("-1");
    printf("\n");

    return 0;
}
