#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    map<string, int> m = {{"monday", 0}, {"tuesday", 1}, {"wednesday", 2}, {"thursday", 3}, {"friday", 4},
                          {"saturday", 5}, {"sunday", 6}};
    
    string d1, d2;
    cin >> d1 >> d2;
    
    if ((m[d1] + 31) % 7 == m[d2] || (m[d1] + 30) % 7 == m[d2] || (m[d1] + 28) % 7 == m[d2]) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
