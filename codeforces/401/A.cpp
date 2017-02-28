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

    int n, x;
    cin >> n >> x;

    n = (n % 6);

    vector<vector<int>> v = {{0,1,2}, {1,0,2}, {1,2,0}, {2,1,0}, {2,0,1}, {0,2,1}};
    printf("%d\n", v[n][x]);

    return 0;
}
