#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

// 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12
// 00, 01, 02, 03, .., 22, 23
int main()
{
    ios_base::sync_with_stdio(false);
    
    int format;
    scanf("%d", &format);
    
    int h1, h2, m1, m2;
    char s[20];
    scanf("%s", s);
    h1 = s[0] - 48;
    h2 = s[1] - 48;
    m1 = s[3] - 48;
    m2 = s[4] - 48;
    
    if (format == 12) {
        if (h1 == 1 && h2 > 2) {
            h2 = 2;
        } else if (h1 > 1) {
            h1 = (h2 == 0) ? 1 : 0;
        } else if (h1 == 0 && h2 == 0) {
            h2 = 1;
        }
    } else {
        if (h1 == 2 && h2 > 3) {
            h2 = 3;
        } else if (h1 > 2) {
            h1 = 1;
        }
    }

    if (m1 > 5) {
        m1 = 4;
    }
    
    printf("%d%d:%d%d\n", h1, h2, m1, m2);
    
    return 0;
}
