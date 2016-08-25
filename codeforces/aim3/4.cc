#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    
    bool possible = true;
    
    int numberOfZeros = 0;
    ll x = 1 + (8 * a);
    if (static_cast<ll>(sqrt(x)) * static_cast<ll>(sqrt(x)) - x != 0) {
        possible = false;
    } else {
        numberOfZeros = (1 + sqrt(x)) / 2;
    }
    
    if (numberOfZeros == 1 && b == 0 && c == 0) {
        numberOfZeros = 0;
    }
    
    int numberOfOnes = 0;
    ll y = 1 + (8 * d);
    if (static_cast<ll>(sqrt(y)) * static_cast<ll>(sqrt(y)) - y != 0) {
        possible = false;
    } else {
        numberOfOnes = (1 + sqrt(y)) / 2;
    }
    
    if (numberOfOnes == 1 && b == 0 && c == 0) {
        numberOfOnes = 0;
    }
    
    if (numberOfOnes == 0 && numberOfZeros == 0) {
        numberOfZeros = 1;
    }
    
    if (possible) {
        possible = numberOfOnes * numberOfZeros == (b + c);
    }
    
    if (possible) {       
        while (numberOfOnes || numberOfZeros) {
            if (numberOfOnes <= b) {
                printf("0");
                b -= numberOfOnes;
                numberOfZeros--;
            } else if (numberOfZeros <= c) {
                printf("1");
                c -= numberOfZeros;
                numberOfOnes--;
            }
        }            
    } else {
        printf("Impossible");
    }
    
    printf("\n");
    
    return 0;
}
