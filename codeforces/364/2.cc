#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

#define ll long long

int main()
{
    int64_t n, m;
    cin >> n >> m;
    
    set<int64_t> rookRow, rookCol;
        
    int64_t currRows = n;
    int64_t currCols = n;
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        
        bool prevBombOnRow = rookRow.count(x) > 0;
        bool prevBombOnCol = rookCol.count(y) > 0;
        
        if (!prevBombOnRow) currRows--;
        if (!prevBombOnCol) currCols--;
        
        if (!prevBombOnRow) rookRow.insert(x);
        if (!prevBombOnCol) rookCol.insert(y);
                
        cout << (currRows * currCols) << " ";
    }
    
    return 0;
}
