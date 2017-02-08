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
      
    string s;  
    cin >> s;
    
    vector<bool> broken(s.size(), false);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '!') broken[i] = true;
    }
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '!') {
            for (int j = i; j >= 0; j -= 4) s[j] = s[i];
            for (int j = i; j < s.size(); j += 4) s[j] = s[i];
        }
    }
    
    vector<int> ans(255, 0);
    for (int i = 0; i < broken.size(); i++) {
        if (broken[i]) ans[s[i]]++;
    }
    
    printf("%d %d %d %d\n", ans['R'], ans['B'], ans['Y'], ans['G']);
    
    return 0;
}
