#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll t;
    scanf("%lld", &t);
    
    vector<ll> tree(524288, 0);
    for (ll i = 0; i < t; i++) {
        char a;
        char n[20];
        
        getchar();
        scanf("%c %s", &a, n);
        bitset<20> bs(0);
        
        int k = strlen(n) - 1;
        for (int j = 0; j < strlen(n); j++, k--) {
            int digit = n[j] - 48;
            if (digit % 2 != 0) bs.set(k);
        }
        
        ll idx = bs.to_ulong();
        
        if (a == '+') tree[idx]++;
        else if (a == '-') tree[idx]--;
        else printf("%lld\n", tree[idx]);
    }
    
    return 0;
}
