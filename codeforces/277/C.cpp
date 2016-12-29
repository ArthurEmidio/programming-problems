#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    p--;
    
    if (p >= n/2) p = (n-1)-p;
    
    string s;
    cin >> s;
    
    int start = -1, end = -1, ans = 0;    
    for (int i = 0; i < n/2; i++) {
        int j = (n-1)-i;
        int diff = min(min(abs(s[i] - s[j]), abs(s[i] - 'a') + abs(s[j] - 'z') + 1), abs(s[j] - 'a') + abs(s[i] - 'z') + 1);
        if (diff) {
            ans += diff;
            if (start == -1) start = i;
            end = i;
        }
    }
           
    if (!ans) {
        printf("0\n");
    } else {
        ans += min(abs(p - start), abs(p - end)) + abs(end - start);
        printf("%d\n", ans);
    }
    
    return 0;
}
