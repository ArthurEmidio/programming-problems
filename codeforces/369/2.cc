#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

inline bool isMagicSquare(const vector<vector<ll>> &matrix)
{
    const ll n = matrix.size();
    
    ll res = 0;
    for (ll i = 0; i < matrix.size(); i++) {
        res += matrix[0][i];
    }
    
    ll diag = 0;
    ll secDiag = 0;
    bool rowColValid = true;
    
    for (ll i = 0; i < n; i++) {
        ll rowCount = 0;
        ll colCount = 0;
        
        for (ll j = 0; j < matrix.size(); j++) {
            rowCount += matrix[i][j];
            colCount += matrix[j][i];
        }
        
        if (rowCount != res || colCount != res) {
            rowColValid = false;
            break;
        }
        
        diag += matrix[i][i];
        secDiag += matrix[n - i - 1][i];
    }
    
    return rowColValid && diag == res && secDiag == res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n;
    scanf("%lld", &n);
    
    if (n == 1) {
        scanf("%lld", &n);
        printf("1\n");
    } else {
        vector<vector<ll>> matrix(n, vector<ll>(n));
        pair<ll, ll> zeroPos;
        ll maxSum = 0;
    
        for (ll i = 0; i < n; i++) {
            ll colSum = 0;
            for (ll j = 0; j < n; j++) {
                scanf("%lld", &(matrix[i][j]));
                colSum += matrix[i][j];
                if (matrix[i][j] == 0) zeroPos = make_pair(i, j);
            }
            maxSum = max(colSum, maxSum);
        }
        
        ll tot = maxSum;
        for (ll i = 0; i < n; i++) tot -= matrix[zeroPos.first][i];
        matrix[zeroPos.first][zeroPos.second] = tot;
    
        if (tot > 0 && isMagicSquare(matrix)) {
            printf("%lld\n", tot);
        } else {
            printf("-1\n");
        }
    }
    
    return 0;
}
