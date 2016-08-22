#include <iostream>
#include <limits>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define ll long long
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    bool isBlackWhite = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char color;
            cin >> color;
            if (isBlackWhite && (color == 'C' || color == 'M' || color == 'Y')) {
                isBlackWhite = false;
            }
        }
    }
    
    printf("#%s\n", isBlackWhite ? "Black&White" : "Color");
    
    return 0;
}
