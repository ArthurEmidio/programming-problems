#include <bits/stdc++.h>

using namespace std;

#define oo 9223372036854775807
#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vector<ii>> roads(5005);
ll dp[5005][5005];
ll n, m, T;

// f(u,v) = min dist from u to n with exactly v vertices
ll solve(int node, int vertices)
{    
    ll &best = dp[node][vertices];
    
    if (best != -1) return best;
    if (vertices == 0) return (node == n-1) ? 0 : oo;
    
    best = oo;
    for (ii p : roads[node]) {
        ll t = solve(p.first, vertices - 1);
        if (t != oo) best = min(t + p.second, best);
    }
                
    return best;
}

void printSol(int node, int vertices)
{
    if (vertices == 0) return;

    ll saved = dp[node][vertices];
    for (ii p : roads[node]) {
        if (solve(p.first, vertices - 1) + p.second == saved) {
            printf("%d ", p.first + 1);
            printSol(p.first, vertices - 1);
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof dp);    
    scanf("%lld %lld %lld", &n, &m, &T);
    
    for (int i = 0; i < m; i++) {
        int orig, dest, t;
        scanf("%d %d %d", &orig, &dest, &t);        
        roads[orig - 1].push_back({dest - 1, t});           
    }
    
    ll sol;
    int i = n;
    for (i = n; i > 0; i--) {
        sol = solve(0, i);
        if (sol != -1 && sol <= T) break;
    }
    printf("%d\n", i+1);
          
    printf("1 ");
    printSol(0, i);
    printf("\n");
    
    return 0;
}
