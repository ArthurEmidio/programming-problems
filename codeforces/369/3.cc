#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    vector<int> trees(n);
    int prevColor;
    scanf("%d", &prevColor);
    trees[0] = prevColor;
    
    int groups = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d" &trees[i]);
        if (prevColor != trees[i]) {
            groups++;
            prevColor = trees[i];
        }        
    }
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
        }
    }
    
    return 0;
}
