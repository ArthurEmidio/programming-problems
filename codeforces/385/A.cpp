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
    
    set<string> strings;
    strings.insert(s);
    
    for (int i = 0; i < s.size(); i++) {
        char c = s.back();
        s.erase(s.size() - 1, 1);
        s = c + s;
        strings.insert(s);
    }
    
    cout << strings.size() << endl;
    
    return 0;
}
