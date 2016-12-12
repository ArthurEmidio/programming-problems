#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mat[5][5];
    
    pair<int, int> pos;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 1) pos = make_pair(i, j);
        }
    }
    
    int ans = abs(pos.first - 2) + abs(pos.second - 2);
    cout << ans << endl;
    
    return 0;
}