#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    char c;
    int state = 1;
    string s;
    cin >> s;
    
    const int strSize = s.size() - 1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        
        if (state == 1) {
            if (c == 'a' && i != strSize) {
                printf("%c", c);
            } else {
                state = 2;
                printf("%c", (c == 'a') ? 'z' : c - 1);
            }
        } else if (state == 2) {
            if (c == 'a') {
                state = 3;
                printf("%c", c);
            } else {
                printf("%c", c - 1);
            }            
        } else {
            printf("%c", c);
        }
    }
    
    printf("\n");
            
    return 0;
}
