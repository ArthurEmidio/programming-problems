#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int caseN = 1;
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        
        int a = 0;
        int b = 0;
        for (int i = 0; i < n; i++) {
            int e;
            cin >> e;
            if (e == 0) {
                b++;
            } else {
                a++;
            }
        }
        
        cout << "Case " << caseN << ": " << (a - b) << endl;
        caseN++;
    }
    
    return 0;
}
