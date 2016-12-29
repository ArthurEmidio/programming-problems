#include <bits/stdc++.h>

using namespace std;

istringstream ss;
int depth = 0;
map<int, vector<string>> m;

void f(int level)
{
    string text, childrenStr;
    getline(ss, text, ',');
    getline(ss, childrenStr, ',');
    int children = stoi(childrenStr);
    
    m[level].push_back(text);
    depth = max(depth, level);
    for (int i = 0; i < children; i++) f(level+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    ss = istringstream(s);
        
    while (!ss.eof()) f(1);
    
    cout << depth << endl;
    for (const pair<int, vector<string>> &p : m) {
        for (const string &s : p.second) {
            cout << s << " ";
        }
        cout << endl;
    }
    
    return 0;
}
