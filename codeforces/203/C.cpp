#include <bits/stdc++.h>

using namespace std;

#define mp(i,j) make_pair(i,j)
#define ff first
#define ss second

typedef pair<int,int> ii;
typedef pair<int, char> ic;

int main()
{
    char inv[255];
    inv['D'] = 'U'; inv['U'] = 'D';
    inv['L'] = 'R'; inv['R'] = 'L';
    
    int n;
    scanf("%d", &n);
    
    vector<ii> bombs(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bombs[i].ff, &bombs[i].ss);
    }
    
    sort(bombs.begin(), bombs.end(), [](const ii &b1, const ii &b2) {
        return abs(b1.ff) + abs(b1.ss) < abs(b2.ff) + abs(b2.ss);
    });
    
    int k = 0;
    vector<vector<ic>> ans;
    
    for (ii &b : bombs) {
        vector<ic> path;
        
        if (b.ff) {
            if (b.ff < 0) path.push_back(mp(abs(b.ff), 'L'));
            else path.push_back(mp(abs(b.ff), 'R'));
            k += 2;
        } 
        
        if (b.ss) {
            if (b.ss < 0) path.push_back(mp(abs(b.ss), 'D'));
            else path.push_back(mp(abs(b.ss), 'U'));
            k += 2;
        }
        
        k += 2;
        ans.push_back(path);
    }
    
    printf("%d\n", k);
    for (vector<ic> &v : ans) {
        for (ic &c : v) printf("1 %d %c\n", c.ff, c.ss);
        printf("2\n");
        for (ic &c : v) printf("1 %d %c\n", c.ff, inv[c.ss]);
        printf("3\n");
    }
    
    return 0;
}