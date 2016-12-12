#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, n1, n2;
    cin >> n >> n1 >> n2;
    
    vector<int> wealth(n);
    for (int i = 0; i < n; i++) {
        cin >> wealth[i];
    }
    
    sort(wealth.begin(), wealth.end(), greater<int>());
    
    int maxN = max(n1, n2);
    int minN = min(n1, n2);
    
    double city1 = 0;
    for (int i = 0; i < minN; i++) {
        city1 += wealth[i];
    }
    
    double city2 = 0;
    for (int i = 0; i < maxN; i++) {
        city2 += wealth[i + minN];
    }
    
    double ans = (city1 / minN) + (city2 / maxN);
    printf("%.8f\n", ans);
    
    return 0;
}
