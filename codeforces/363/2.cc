#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> wallsPerRow(n, 0);
    vector<int> wallsPerCol(m, 0);
    char grid[n][m];
    int wallsCount = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char s;
            cin >> s;
            grid[i][j] = s;
            
            if (s == '*') {
                wallsCount++;
                wallsPerRow[i]++;
                wallsPerCol[j]++;
            }
        }
    }
        
    bool valid = false;
    pair<int, int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int walls = (wallsPerRow[i] + wallsPerCol[j]);
            if (grid[i][j] == '*') {
                walls--;
            }
                                    
            if (walls >= wallsCount) {
                ans = make_pair(i + 1, j + 1);
                valid = true;
                goto finish;
            }
        }
    }
    
    finish:
    if (valid) {
        cout << "YES" << endl << ans.first << " " << ans.second << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
