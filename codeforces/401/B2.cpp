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

int n;
vector<int> v1, v2;

int solve1()
{
    return 0;
}

int solve2()
{
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++) v1[i] = (s1[i] - '0'), v2[i] = (s2[i] - '0');
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());

    printf("%d\n%d\n", solve1(), solve2());

    return 0;
}
