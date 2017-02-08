#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    if (a == b) {
        printf("-1\n");
    } else {
        printf("%d\n", max(a.size(), b.size()));
    }

    return 0;
}
