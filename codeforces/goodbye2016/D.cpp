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
typedef pair<int,int> ii;

bool vis[300][300][6][32][4] = {};
set<ii> vis2;
vector<int> e;

ii diag[4] = {{-1, 1}, {-1, -1}, {1, -1}, {1, 1}}; 
ii stra[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

ii trans_diag[4] = {{0,1}, {1,2}, {2,3}, {3,0}};
ii trans_stra[4] = {{0,3}, {0,1}, {1,2}, {2,3}};

/*
transitions:
    diag:
        0: 0, 1
        1: 1, 2
        2: 2, 3
        3: 3, 0

    stra:
        0: 0, 3
        1: 0, 1
        2: 1, 2
        3: 2, 3
*/

void dfs(int i, int j, int left, int idx, int dir)
{
    if (vis[i][j][left][idx][dir]) return;
    vis[i][j][left][idx][dir] = true;
    vis2.insert({i,j});
    
    if (left > 1) {
        if (idx % 2 == 0) dfs(i + stra[dir].ff, j + stra[dir].ss, left-1, idx, dir);
        else dfs(i + diag[dir].ff, j + diag[dir].ss, left-1, idx, dir);
    } else {
        if (idx + 1 >= e.size()) return;
        if (idx % 2 == 0) {
            ii tran = trans_stra[dir];
            dfs(i + diag[tran.ff].ff, j + diag[tran.ff].ss, e[idx+1], idx + 1, tran.ff);
            dfs(i + diag[tran.ss].ff, j + diag[tran.ss].ss, e[idx+1], idx + 1, tran.ss);
        } else {
            ii tran = trans_diag[dir];
            dfs(i + stra[tran.ff].ff, j + stra[tran.ff].ss, e[idx+1], idx + 1, tran.ff);
            dfs(i + stra[tran.ss].ff, j + stra[tran.ss].ss, e[idx+1], idx + 1, tran.ss);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    
    e.assign(n, 0);
    for (int i = 0; i < n; i++) scanf("%d", &e[i]);
    dfs(150, 150, e[0], 0, 0);
    
    cout << vis2.size() << endl;
    
    return 0;
}
