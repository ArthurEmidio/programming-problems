#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    
    int a = abs(x1 - x2);
    int b = abs(x2 - x3);
    int c = abs(x1 - x3);
    
    printf("%d\n", max(max(a, b), c));
    
    return 0;
}
