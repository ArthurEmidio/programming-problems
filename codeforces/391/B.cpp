#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{   
    int n;
    scanf("%d", &n);
    
    int look[100005] = {};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        look[x]++;
    }
    
    int ans = 1;
    for (int i = 2; i <= 100000; i++) {
        int cnt = 0;
        for (int j = i; j <= 100000; j += i) cnt += look[j];
        ans = max(ans, cnt);
    }
    
    cout << ans << endl;
    
    return 0;
}