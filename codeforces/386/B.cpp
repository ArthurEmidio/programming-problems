#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    string s;
    cin >> n >> s;
    
    string ans = s;
    for (char &c : ans) c = 'X';
    
    bool turn = n%2==0 ? false : true;
    int j = n%2==0 ? (n/2)-1 : n/2;
    int k = j;
    
    for (int i = 0; i < n; i++) {
        if (turn) { ans[j] = s[i]; k--; }
        else { ans[k] = s[i]; j++; }
        turn = !turn;
    }
    
    cout << ans << endl;
    
    return 0;
}
