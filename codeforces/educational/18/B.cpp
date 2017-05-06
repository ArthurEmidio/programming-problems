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

    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> v(k);
    for (int i = 0; i < k; i++) scanf("%d", &v[i]);

    vector<int> players(n);
    for (int i = 0; i < n; i++) players[i] = i+1;

    int curr = 0;
    for (int x : v) {
        int y = x % n;
        while (y--) curr = (curr + 1) % n;
        printf("%d ", players[curr]);
        players.erase(players.begin() + curr);
        if (curr == players.size()) curr = 0;
        n--;
    }
    printf("\n");

    return 0;
}
