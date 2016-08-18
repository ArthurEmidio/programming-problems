#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    for (;;) {
        int n = 0;
        char c, prevC;
        scanf("%c", &c);
        
        if (c == 'E') {
            string s;
            cin >> s;
            break;
        }
                
        while (c != '\n') {
            n++;
            prevC = c;
            scanf("%c", &c);
        }
        
        int x = 0;
        if (n > 1 || prevC != '1') {
            x++;         
            while (n != 1) {
                n = log10(n) + 1;
                x++;
            }
        }
        
        cout << x + 1 << endl;
    }
    
    return 0;
}

