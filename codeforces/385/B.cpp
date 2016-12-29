#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{    
    int n, m;
    cin >> n >> m;
    
    char mat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    int beginX, beginY;
    int endX, endY;
    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            if (mat[i][j] == 'X') {
                beginY = i;
                beginX = j;
                
                endX = -1;             
                for (int k = beginX; k < m; k++) {
                    if (mat[beginY][k] == '.') {
                        endX = k-1;
                        break;
                    }
                }
                if (endX == -1) endX = m-1;
                
                endY = -1;             
                for (int k = beginY; k < n; k++) {
                    if (mat[k][beginX] == '.') {
                        endY = k-1;
                        break;
                    }
                }
                if (endY == -1) endY = n-1;
                
                found = true;
            }
        }
    }
        
    bool ans = true;
    for (int i = 0; i < n && ans; i++) {
        for (int j = 0; j < m && ans; j++) {
            if ((mat[i][j] == 'X' && (i < beginY || i > endY || j < beginX || j > endX)) ||
                (mat[i][j] == '.' && (i >= beginY && i <= endY && j >= beginX && j <= endX))) {                
                ans = false;
            }
        }
    }
    
    printf("%s\n", ans ? "YES" : "NO");
    
    return 0;
}
