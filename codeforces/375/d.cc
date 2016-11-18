#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

vector<vector<char>> matrix;
vector<vector<char>> ans;
int n, m, k;

int lakeSize(int i, int j)
{   
    int count = 0;
    
    if (matrix[i][j] == '.') {
        matrix[i][j] = 'X';
        
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        int count4 = 0;
        
        if (i > 0) count1 = lakeSize(i - 1, j);
        if (i < n - 1) count2 = lakeSize(i + 1, j);
        if (j > 0) count3 = lakeSize(i, j - 1);
        if (j < m - 1) count4 = lakeSize(i, j + 1);
        
        if (i == 0 || j == 0 || i == n-1 || j == m-1 || count1 == -1 || count2 == -1 || count3 == -1 || count4 == -1) {
            count = -1;
        } else {
            count = 1 + count1 + count2 + count3 + count4;
        }
    }
    
    return count;
}

void fill(int i, int j)
{
    if (ans[i][j] == '.') {
        ans[i][j] = '*';
        
        if (i > 0) fill(i - 1, j);
        if (i < n - 1) fill(i + 1, j);
        if (j > 0) fill(i, j - 1);
        if (j < m - 1) fill(i, j + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m >> k;
    
    matrix = vector<vector<char>>(n, vector<char>(m));
    ans = vector<vector<char>>(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            ans[i][j] = matrix[i][j];
        }
    }
        
    set<pair<int, pair<int, int>>> lakes;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') {
                int ls = lakeSize(i, j);
                if (ls > 0) {
                    lakes.insert(make_pair(ls, make_pair(i, j)));
                }
            }
        }
    }
        
    int changes = 0;
    int toBeRemoved = lakes.size() - k;
    for (int i = 0; i < toBeRemoved; i++) {
        pair<int, pair<int, int>> lake = *(lakes.begin());
        changes += lake.first;
        fill(lake.second.first, lake.second.second);        
        lakes.erase(lakes.begin());
    }
    
    printf("%d\n", changes);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
