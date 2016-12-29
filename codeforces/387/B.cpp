#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{    
    int n;
    cin >> n;
    
    vector<char> v(255, 0);
    string s;
    int quest = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        v[c]++;
        if (c == '?') quest++;
        s += c;
    }
    
    int m = max(max(v['C'], v['G']), max(v['A'], v['T']));
    int rem = (m - v['C']) + (m - v['G']) + (m - v['A']) + (m - v['T']);
        
    if (rem > quest || (quest-rem) % 4 != 0) {
        printf("===\n");
    } else {
        vector<char> y = {'C', 'G', 'A', 'T'};
        int plus = (quest - rem) / 4;
        int curr = 0;
        
        for (char z : y) {
            int add = (m - v[z]) + plus;
            while (add) {
                while (s[curr] != '?') curr++;
                s[curr] = z;
                add--;
            }
        }
        cout << s << endl;
    }
        
    return 0;
}
