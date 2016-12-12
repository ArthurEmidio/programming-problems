#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int n;
int pos = 10;

double solve(int i, int j)
{
    static double dp[22][22];
    static bool mark[22][22] = {};
    
    if (i == n) {
        return j == pos ? 1.0 : 0.0;
    }
    
    if (mark[i][j]) return dp[i][j];
    mark[i][j] = true;
    double &ans = dp[i][j];
    
    if (s2[i] != '?') return ans = solve(i + 1, s2[i] == '+' ? (j+1) : (j-1));
    return ans = 0.5*solve(i + 1, j + 1) + 0.5*solve(i + 1, j - 1);
}

int main()
{
    cin >> s1 >> s2;
    n = s1.size();
    for (char c : s1) pos += c == '+' ? 1 : -1;
    
    printf("%.10f\n", solve(0, 10));
    
    return 0;
}