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

    map<int, int> s;
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        s[a]++;
    }

    for (int i = 0; i < k; i++) {
        bool ok = true;
        map<int, int> s1;
        for (auto it = s.begin(); it != s.end(); it++) {
            int key = it->first;
            int occ = it->second;
            int b = (key ^ x);

            if (ok) {
                int x = (occ + 1) / 2;
                if (x) s1[b] += x;
                if (occ - x) s1[key] += occ - x;
            } else {
                int x = occ / 2;
                if (x) s1[b] += x;
                if (occ - x) s1[key] += occ - x;
            }

            if (occ % 2 != 0) ok = !ok;
        }

        s = s1;
    }

    int less = s.begin()->first;
    int great = prev(s.end())->first;

    printf("%d %d\n", great, less);

    return 0;
}
