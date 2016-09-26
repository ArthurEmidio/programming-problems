#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    
    map<char, int> readChars;
    int begin = 0;
    
    bool valid = false;
    int i = 0;
    for (char c : s) {
        if (c != '?' && readChars.count(c) && readChars[c] >= begin) {
            begin = readChars[c] + 1;
        }
        if (c != '?') readChars[c] = i;
        
        if ((i - begin) == 25) {
            valid = true;
            break;
        }
        
        ++i;
    }
        
    if (valid) {
        set<char> missing;
        for (char c = 'A'; c <= 'Z'; c++) missing.insert(c);
        
        for (int j = begin; j <= i; j++) {
            if (s[j] != '?') {
                missing.erase(s[j]);
            }
        }
        
        for (int j = begin; j <= i; j++) {
            if (s[j] == '?') {
                s[j] = *missing.begin();
                missing.erase(missing.begin());
            }
        }
    }
    
    if (valid) {
        for (char c : s) {
            printf("%c", c == '?' ? 'A' : c);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
    
    return 0;
}
