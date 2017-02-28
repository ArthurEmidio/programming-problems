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

    int hist[1100] = {};
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        hist[a]++;
    }

    for (int i = 0; i < k; i++) {
        bool ok = true;
        int hist2[1100] = {};
        for (int j = 0; j < 1100; j++) {
            int occ = hist[j];
            int b = (j ^ x);

            if (ok) {
                int x = (occ + 1) / 2;
                if (x) hist2[b] += x;
                if (occ - x) hist2[j] += occ - x;
            } else {
                int x = occ / 2;
                if (x) hist2[b] += x;
                if (occ - x) hist2[j] += occ - x;
            }

            if ((occ & 1) != 0) ok = !ok;
        }

        for (int j = 0; j < 1100; j++) hist[j] = hist2[j];
    }

    int less = -1, great = -1;
    for (int i = 0; i < 1100 && less == -1; i++) if (hist[i]) less = i;
    for (int i = 1099; i >= 0 && great == -1; i--) if (hist[i]) great = i;

    printf("%d %d\n", great, less);

    return 0;
}
