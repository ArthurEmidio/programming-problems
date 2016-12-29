#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    string curr;
    cin >> curr;
    
    string next;
    int nextDeadD = 0;
    int nextDeadR = 0;
    
    int limD = 0, limR = 0;
    for (char c : curr) {
        if (c == 'D') limD++;
        else limR++;
    }
    
    while (limD > 0 && limR > 0) {        
        for (int i = 0; i < curr.size() && limD > 0 && limR > 0; i++) {
            if (curr[i] == 'D') {
                if (nextDeadD) {
                    nextDeadD--;
                } else {
                    next += 'D';
                    nextDeadR++;
                    limR--;
                }
            } else {
                if (nextDeadR) {
                    nextDeadR--;
                } else {
                    next += 'R';
                    nextDeadD++;
                    limD--;
                }
            }
        }
        curr = next;
        next.clear();
    }
    
    if (!limR) printf("D\n");
    else printf("R\n");
    
    return 0;
}
