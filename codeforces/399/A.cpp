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
    scanf("%d", &n);

    multiset<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v.insert(x);
    }

    if (!v.empty()) v.erase(*v.begin());
    if (!v.empty()) v.erase(*prev(v.end()));
    printf("%lu\n", v.size());

    return 0;
}
