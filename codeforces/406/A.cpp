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

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int ans = -1;
    for (int i = 0; i < 500 && ans == -1; i++) {
        for (int j = 0; j < 500 && ans == -1; j++) {
            if (a*i + b == c*j + d) ans = a*i + b;
        }
    }

    printf("%d\n", ans);

    return 0;
}
