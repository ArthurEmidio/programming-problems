#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    bool isBerland = false;
    bool hadZero = false;
    
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (b == 0) {
            if (!hadZero) {
                hadZero = true;
                isBerland = true;
            } else {
                isBerland = false;
                break;
            }
        }
    } 
    
    if (n == 1) {
        isBerland = !hadZero;
    }
    
    printf("%s\n", isBerland ? "YES" : "NO");
    
    return 0;
}
