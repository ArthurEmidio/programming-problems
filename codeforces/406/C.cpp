#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
typedef pair<int, int> ii;

vector<int> sets[2];
int G[7005][2];

bool lost(int v, int p)
{
    return G[v][p] < 0 && -G[v][p] >= sets[p].size();
}

bool won(int v, int p)
{
    return G[v][p] == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);
    n--;

    for (int i = 0; i < 2; i++) {
        int k;
        scanf("%d", &k);
        sets[i].assign(k, 0);
        for (int j = 0; j < k; j++) scanf("%d", &sets[i][j]);
    }

    queue<ii> q;
    G[0][0] = -sets[0].size(); q.push({0, 0});
    G[0][1] = -sets[1].size(); q.push({0, 1});

    while (!q.empty()) {
        ii curr = q.front(); q.pop();
        int obj = curr.ff;
        int me = curr.ss;
        int adv = me ^ 1;

        bool lose = lost(obj, me);

        for (int mv : sets[adv]) {
            int bef = obj - mv;
            if (bef < 0) bef = n + bef + 1;

            if (won(bef, adv) || lost(bef, adv)) continue;

            if (lose) {
                G[bef][adv] = 1;
                q.push({bef, adv});
            } else {
                G[bef][adv]--;
                if (lost(bef, adv)) q.push({bef, adv});
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            if (won(j, i)) printf("Win");
            else if (lost(j, i)) printf("Lose");
            else printf("Loop");
            printf("%c", j == n ? '\n' : ' ');
        }
    }

    return 0;
}
