#include <bits/stdc++.h>

using namespace std;

vector<int> prep(const string &s)
{
    vector<int> p(s.size() + 1, -1);    
    int i = 0, j = -1;
    while (i < s.size()) {
        while (j >= 0 && s[i] != s[j]) j = p[j];
        i++, j++;
        p[i] = j;
    }
    return p;
}

int main()
{
    string s;
    cin >> s;
    
    vector<int> p = prep(s);    
    int i;
    for (i = 1; i < p.size()-1; i++) {
        if (p.back() == p[i]) break;
    }

    if (!p.back() || (i == p.size() - 1 && p[p.back()] == 0)) {
        printf("Just a legend\n");
    } else {
        if (i == p.size() - 1) p[i] = p[p.back()];
        for (int j = 0; j < p[i]; j++) printf("%c", s[j]);
        printf("\n");
    }
    
    return 0;
}
