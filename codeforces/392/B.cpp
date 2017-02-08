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

string s;
vector<set<char>> possible;

void fix(int i)
{
    for (int j = i-1; j >= i-3 && j >= 0; j--) {
        possible[i].erase(s[j]);
    }
    
    for (int j = i+1; j <= i+3 && j < s.size(); j++) {
        possible[i].erase(s[j]);
    }
    
    if (possible[i].size() == 1) s[i] = *possible[i].begin();
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> s;
    
    vector<bool> broken(s.size(), false);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '!') broken[i] = true;
    }
    
    possible.assign(s.size(), set<char>());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '!') possible[i] = set<char>({s[i]});
        else possible[i] = set<char>({'B', 'R', 'G', 'Y'});
    }
    
    bool done = false;
    while (!done) {
        for (int i = 0; i < s.size(); i++) if (s[i] == '!') fix(i);        
        done = true;
        for (int i = 0; i < s.size(); i++) if (possible[i].size() > 1) done = false;
    }
    
    vector<int> ans(255, 0);
    for (int i = 0; i < broken.size(); i++) {
        if (broken[i]) ans[*(possible[i].begin())]++;
    }
    
    printf("%d %d %d %d\n", ans['R'], ans['B'], ans['Y'], ans['G']);
    
    return 0;
}
