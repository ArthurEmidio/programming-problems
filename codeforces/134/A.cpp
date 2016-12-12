#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

using Point = pair<int,int>;

vector<Point> drifts;
vector<vector<Point>> rows;
vector<vector<Point>> cols;
set<Point> vis;

void dfs(const Point &p)
{
    if (vis.count(p)) return;
    vis.insert(p);
    
    for (const Point &neighbor : rows[p.ff]) dfs(neighbor);
    for (const Point &neighbor : cols[p.ss]) dfs(neighbor);
}

int main()
{
    int n;
    cin >> n;
    
    drifts.assign(n, Point());
    rows.assign(1005, vector<Point>());
    cols.assign(1005, vector<Point>());
    
    for (int i = 0; i < n; i++) {
        cin >> drifts[i].ff >> drifts[i].ss;
        rows[drifts[i].ff].push_back(drifts[i]);
        cols[drifts[i].ss].push_back(drifts[i]);
    }
    
    int ans = 0;
    for (const Point &p : drifts) {
        if (!vis.count(p)) {
            dfs(p);
            ans++;
        }
    }
    
    cout << ans-1 << endl;
    
    return 0;
}
