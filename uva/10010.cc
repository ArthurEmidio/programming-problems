#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> coordinates = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int solve(int i, int j, int charIdx, const string &word, int mode, vector<string> &matrix, int m, int n)
{
    if (charIdx == word.size()) return true;
    if (i < 0 || i >= m || j < 0 || j >= n) return false;
    
    bool valid = false;
    if (matrix[i][j] == word[charIdx]) {
        char saved = matrix[i][j];
        matrix[i][j] = '.';
        valid = solve(i + coordinates[mode].first, j + coordinates[mode].second, charIdx + 1, word, mode, matrix, m, n);
        matrix[i][j] = saved;
    }
    
    return valid;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        
        vector<string> matrix(m);
        for (int i = 0; i < m; i++) {
            matrix[i].reserve(n);
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                matrix[i][j] = tolower(c);
            }
        }
        
        int k;
        cin >> k;
        
        while (k--) {
            string word;
            cin >> word;
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            bool found = false;
            for (int i = 0; i < m && !found; i++) {
                for (int j = 0; j < n && !found; j++) {
                    for (int l = 0; l < 8 && !found; l++) {
                        if (solve(i, j, 0, word, l, matrix, m, n)) {
                            printf("%d %d\n", i+1, j+1);
                            found = true;
                        }
                    }
                }
            }
        }
        
        if (t > 0) printf("\n");
    }
    
    return 0;
}
