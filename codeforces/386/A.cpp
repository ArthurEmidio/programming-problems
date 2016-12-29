#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    while (a*4 > c || a *2 > b) a--;
    
    cout << (7*a) << endl;
    
    return 0;
}
