#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    getchar();
    
    string res;
    bool valid = false;
    
    for (int i = 0; i < n; i++) {
        char s1, s2, tmp, s3, s4;
        scanf("%c%c%c%c%c", &s1, &s2, &tmp, &s3, &s4);
        getchar();
        
        if (!valid && s1 == 'O' && s2 == 'O') {
            valid = true;
            res += "++";
        } else {
            res += s1;
            res += s2;
        }
        
        res += '|';
        
        if (!valid && s3 == 'O' && s4 == 'O') {
            valid = true;
            res += "++";
        } else {
            res += s3;
            res += s4;
        }
        
        res += '\n';
    }
    
    if (valid) {
        cout << "YES" << endl << res;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
