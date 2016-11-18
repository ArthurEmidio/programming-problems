#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    double n, m, a;
    cin >> n >> m >> a;
    printf("%.0f\n", ceil(n / a) * ceil(m / a));
    
    return 0;
}
