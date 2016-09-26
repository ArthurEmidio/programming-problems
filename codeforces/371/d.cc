#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n;
    scanf("%lld", &n);
    
    ll x1 = 1, y1 = 1;
    ll x2 = n, y2 = n;
    
    printf("? %lld %lld %lld %lld\n", x1, y1, x2, y2);
    fflush(stdout);
    
    int quant;
    getchar();
    scanf("%d", &quant);
        
    ll last;
    ll largest = n;
    ll smallest = 0;
    while (smallest < largest - 1) {
        y2 = (largest + smallest) / 2;
        
        printf("? %lld %lld %lld %lld\n", x1, y1, x2, y2);
        fflush(stdout);
        getchar();
        scanf("%d", &quant);
        
        if (quant == 1) {
            last = y2;
        }
        
        if (quant != 0) {
            largest = y2;
        } else {
            smallest = y2;
        }
    }
    y2 = last;
    
    cout << "found y2: " << y2 << endl;
    
    largest = n;
    smallest = 0;
    while (smallest < largest - 1) {
        x2 = (largest + smallest) / 2;
        
        printf("? %lld %lld %lld %lld\n", x1, y1, x2, y2);
        fflush(stdout);
        getchar();
        scanf("%d", &quant);
        
        if (quant == 1) {
            last = x2;
        }
        
        if (quant != 0) {
            largest = x2;
        } else {
            smallest = x2;
        }
    }
    x2 = last;
    
    largest = n;
    smallest = 0;
    while (smallest < largest - 1) {
        y1 = (largest + smallest) / 2;
        
        printf("? %lld %lld %lld %lld\n", x1, y1, x2, y2);
        fflush(stdout);
        getchar();
        scanf("%d", &quant);
        
        if (quant == 1) {
            last = y1;
        }
        
        if (quant != 0) {
            largest = y1;
        } else {
            smallest = y1;
        }
    }
    y1 = last;
    
    largest = n;
    smallest = 0;
    while (smallest < largest - 1) {
        x1 = (largest + smallest) / 2;
        
        printf("? %lld %lld %lld %lld\n", x1, y1, x2, y2);
        fflush(stdout);
        getchar();
        scanf("%d", &quant);
        
        if (quant == 1) {
            last = x1;
        }
        
        if (quant != 0) {
            largest = x1;
        } else {
            smallest = x1;
        }
    }
    x1 = last;
    
    ll res1 = x1, res2 = x2, res3 = x2, res4 = y2;
    
    printf("! %lld %lld %lld %lld\n", x1, y1, x2, y2);
    
    return 0;
}
