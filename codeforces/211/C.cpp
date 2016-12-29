#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    vector<pair<int, char>> v;
    int i = 0;
    while (i < s.size()) {
        char c = s[i];
        int j = i;
        while (i < s.size() && c == s[i]) i++;
        v.push_back(make_pair(i - j, c));
    }
    
    for (int i = 0; i < v.size(); i++) {        
        if (v[i].first == 1) {
            printf("%c", v[i].second);
        } else {
            v[i].first = 2;
            if (i+1 < v.size() && v[i+1].first >= 2) v[i+1].first = 1;                         
            printf("%c%c", v[i].second, v[i].second);
        }
    }
    printf("\n");
    
    return 0;
}