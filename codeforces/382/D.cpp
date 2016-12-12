#include <bits/stdc++.h>

using namespace std;

inline bool isPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{    
    int n;
    cin >> n;
    
    int ans = 1;
    if (!isPrime(n)) {
        if (n % 2 == 0 || isPrime(n - 2)) ans = 2;
        else ans = 3;
    }
    
    cout << ans << endl;
    
    return 0;
}