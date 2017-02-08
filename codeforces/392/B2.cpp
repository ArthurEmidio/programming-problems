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
    
    string s2 = s;
    
    bool fixed = false;
    while (!fixed) {
        fixed = true;
        for (int i = 0; i <= s.size() - 4; i++) {
            char &a = s2[i], &b = s2[i+1], &c = s2[i+2], &d = s2[i+3];
        
            int cnt = 0;
            if (a == '!') cnt++;
            if (b == '!') cnt++;
            if (c == '!') cnt++;
            if (d == '!') cnt++;
        
            if (cnt == 1) {
                fixed = false;
                set<char> chars({'B', 'R', 'G', 'Y'});
            
                if (a != '!') chars.erase(a);
                if (b != '!') chars.erase(b);
                if (c != '!') chars.erase(c);
                if (d != '!') chars.erase(d);
            
                char repl = *chars.begin();
                if (a == '!') a = repl;
                if (b == '!') b = repl;
                if (c == '!') c = repl;
                if (d == '!') d = repl;
            }
        }
    }
    
    vector<int> ans(255, 0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '!') ans[s2[i]]++;
    }
    
    printf("%d %d %d %d\n", ans['R'], ans['B'], ans['Y'], ans['G']);
    
    return 0;
}