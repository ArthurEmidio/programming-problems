#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    char a[1000005], b[1000005];
    scanf("%s %s", a, b);
    
    bool ans = false;
    int na = strlen(a), nb = strlen(b);
    if (na == nb) {
        bool zeroA = true, zeroB = true;
        for (int i = 0; i < na && (zeroA || zeroB); i++) {
            if (a[i] == '1') zeroA = false;
            if (b[i] == '1') zeroB = false;
        }
        ans = strcmp(a, b) == 0 || (!zeroA && !zeroB);
    }
    
    printf("%s\n", ans ? "YES" : "NO");
    
    return 0;
}