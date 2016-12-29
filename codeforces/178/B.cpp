#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef pair<int,int> ii;

uint8_t dp[105][205][10005] = {};
int n;
vector<ii> books;

uint8_t f(int i, int j, int k)
{    
    if (i == n) return (k > j) ? 255 : j;    
    uint8_t &ans = dp[i][j][k];
    if (ans) return ans;
    return ans = min(f(i+1, j + books[i].ff, k), f(i+1, j, k + books[i].ss));
}

int main()
{
    scanf("%d", &n);    
    books.assign(n, ii(0,0));
    for (int i = 0; i < n; i++) scanf("%d %d", &books[i].ff, &books[i].ss);
    printf("%d\n", f(0,0,0));
    
    return 0;
}
