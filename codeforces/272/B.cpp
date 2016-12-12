#include <bits/stdc++.h>

using namespace std;

inline bool isValid(const string &s, const string &s2)
{
    for (int i = 0; i < s.size(); i++) {
        if (s2[i] == '?') continue;
        if (s[i] != s2[i]) return false;
    }
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    int finalPos = 0;
    for (char c : s1) {
        finalPos += (c == '+') ? 1 : -1;
    }
    
    int n = s1.size();
    const int lim = pow(2,10);
        
    int possible = 0;
    int tot = 0;
    for (int i = 0; i < pow(2,10); i++) {
        string s;
        
        int pos = 0;
        for (int j = n-1; j >= 0; j--) {
            int bit = (i >> j) & 0x1;
            s += bit ? '+' : '-';
            pos += bit ? 1 : -1;
        }
                
        if (isValid(s, s2)) {
            if (pos == finalPos) possible++;
            tot++;
        }
    }
    
    printf("%.12f\n", possible/(double)tot);
    
    return 0;
}