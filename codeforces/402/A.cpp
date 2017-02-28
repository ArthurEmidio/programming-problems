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

    int n;
    cin >> n;

    int A[6] = {}, B[6] = {};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A[x]++;
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        B[x]++;
    }

    int a = 0, b = 0;
    bool pos = true;
    for (int i = 1; i <= 5; i++) {
        int tot = A[i] + B[i];
        if (tot & 1) pos = false;
        if (A[i] < B[i]) a += (tot / 2) - A[i];
        else b += (tot / 2) - B[i];
    }

    printf("%d\n", a == b && pos ? a : -1);

    return 0;
}
