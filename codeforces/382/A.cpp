#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    
    int g = 0;
    int t = 0;
    
    vector<char> line;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        line.push_back(c);
        if (c == 'T') t = i;
        else if (c == 'G') g = i;
    }
        
    int jmp = k;
    if (g > t) {
        jmp = -jmp;
    }
        
    int i = g;
    bool ans = false;
    while (i >= 0 && i < line.size()) {
        if (i == t) {
            ans = true;
            break;
        } else if (line[i] == '#') {
            break;
        }
        
        i += jmp;
    }
    
    printf("%s\n", ans ? "YES" : "NO");
    
    return 0;
}
