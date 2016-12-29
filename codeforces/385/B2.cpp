#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int main()
{
    int n, m;
    cin >> n >> m;
    
    char mat[n][m];
    ii tl(-1,-1), rb(-1,-1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'X') {
                if (tl.first == -1) tl = {i,j};
                rb = {i,j};
            }
        }
    }
    
    bool ans = true;
    for (int i = 0; i < n && ans; i++) {
        for (int j = 0; j < m && ans; j++) {
            if ((mat[i][j] == 'X' && (i < tl.first || i > rb.first || j < tl.second || j > rb.second)) ||
                (mat[i][j] == '.' && (i >= tl.first && i <= rb.first && j >= tl.second && j <= rb.second))) {
                ans = false;    
            }
        }
    }
    
    printf("%s\n", ans ? "YES" : "NO");
    
    return 0;
}