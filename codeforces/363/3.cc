#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define ll long long

enum Decision {
    CO, EX, RE, UND
};

int main()
{
    int n;
    cin >> n;
    
    Decision lastDecision = RE;
    int rest = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        if (a == 0) {
            rest++;
            lastDecision = RE;
        } else if (a == 1) {
            if (lastDecision != CO) {
                lastDecision = CO;
            } else {
                rest++;
                lastDecision = RE;
            }
        } else if (a == 2) {
            if (lastDecision != EX) {
                lastDecision = EX;
            } else {
                rest++;
                lastDecision = RE;
            }
        } else {
            if (lastDecision == CO) {
                lastDecision = EX;
            } else if (lastDecision == EX) {
                lastDecision = CO;
            } else {
                lastDecision = RE;
            }
        }
    }
        
    cout << rest << endl;
    
    return 0;
}