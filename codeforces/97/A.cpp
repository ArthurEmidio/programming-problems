#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        int p;
        scanf("%d", &p);
        v[p] = i;
    }
    
    for (int i = 1; i <= n; i++) printf("%d ", v[i]);
    printf("\n");
    
    return 0;
}