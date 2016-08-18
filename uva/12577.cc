#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int i = 1;
    while (1) {
        string s;
        cin >> s;
        
        if (s == "*") break;
        
        cout << "Case " << i << ": Hajj-e-";
        if (s == "Hajj") {
            cout << "Akbar" << endl;
        } else {
            cout << "Asghar" << endl;
        }
        i++;
    }
    
    return 0;
}
