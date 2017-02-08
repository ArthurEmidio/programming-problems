#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n;
    string k;
    cin >> n >> k;
    
    ll powers[65];
    powers[0] = 1;
    for (int i = 1; i < 65; i++) powers[i] = powers[i-1] * n;
    
    vector<ll> numbers;
    int i = k.size() - 1;
    while (i >= 0) {
        ll curr = 0;
        ll b = 1;
        
        int lastZero = -1;
        while (i < k.size()) {
            if (curr + max(1, (k[i] - '0')) * b >= n) break;
            if (k[i] == '0' && lastZero == -1) lastZero = i;
            if (k[i] != '0') lastZero = -1;
            
            curr = curr + (k[i] - '0') * b;
            i--;
            b *= 10;
        }
        
        if (lastZero != -1) {
            if (curr) i = lastZero;
            else i = lastZero - 1;
        }
        
        numbers.push_back(curr);
    }
    
    reverse(numbers.begin(), numbers.end());
    
    ll ans = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i]) ans += powers[numbers.size() - 1 - i] * numbers[i];
    }
    cout << ans << endl;
    
    return 0;
}
