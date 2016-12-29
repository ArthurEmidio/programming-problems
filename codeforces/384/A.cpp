#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, a, b;
    cin >> n >> a >> b;
        
    string s;
    cin >> s;
    
    cout << (s[a-1] == s[b-1] ? 0 : 1) << endl;
    
    return 0;
}
