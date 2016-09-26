#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    for (int tn = 1; tn <= t; tn++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        
        string type;
        if (a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0) {
            if (a == b && b == c) {
                type = "Equilateral";
            } else if (a == b || a == c || b == c) {
                type = "Isosceles";
            } else {
                type = "Scalene";
            }
        } else {
            type = "Invalid";
        }
        
        printf("Case %d: %s\n", tn, type.c_str());
    }
    
    return 0;
}
