#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int bs(const vector<int> &v, int x)
{
    auto it = upper_bound(v.begin(), v.end(), x);
    return it - v.begin();
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    
    vector<int> prices;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        prices.push_back(x); 
    }
    sort(prices.begin(), prices.end());
    
    int q;
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        int m;
        scanf("%d", &m);        
        printf("%d\n", bs(prices, m));
    }

    return 0;
}
