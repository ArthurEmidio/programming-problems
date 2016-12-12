#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int prev = s[0];
    int i = 0;
    bool dang = false;
    while (i < s.size()) {
        int count = 0;
        int x = s[i];
        while (i < s.size() && s[i] == x) count++, i++;
        if (count >= 7) {
            dang = true;
            break;
        }
    }
    
    printf("%s\n", dang ? "YES" : "NO");
    
    return 0;
}