#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> mt(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            mt[i].push_back(x);
        }
    }
    
    bool possible = false;
    for (int i = 0; i < m && !possible; i++) {
        for (int j = i; j < m && !possible; j++) {
            possible = true;
            for (int k = 0; k < n && possible; k++) {
                int wrong = 0;
                swap(mt[k][i], mt[k][j]);
                for (int l = 0; l < m && wrong <= 2; l++) {
                    if (mt[k][l] != l+1) wrong++;
                }
                swap(mt[k][i], mt[k][j]);
                if (wrong > 2) possible = false;
            }
        }
    }
    
    printf("%s\n", possible ? "YES" : "NO");
    
    return 0;
}
