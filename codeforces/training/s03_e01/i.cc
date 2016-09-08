#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll t;
    cin >> t;
        
    while (t--) {
        list<char> res;
        auto it = res.begin();
        
        string s;
        cin >> s;
        for (char c : s) {
            if (c == '<') {
                if (it != res.begin()) --it;                
            } else if (c == '>') {
                if (it != res.end()) ++it;
            } else if (c == '-') {
                if (it != res.begin()) res.erase(prev(it));
            } else {
                res.insert(it, c);
            }
        }
        
        for (char c : res) printf("%c", c);
        printf("\n");
    }
    
    return 0;
}
