#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string code;
        cin >> code;
        
        if (code == "1" || code == "4" || code == "78") {
            cout << "+";
        } else if (code.front() == '9' && code.back() == '4') {
            cout << "*";
        } else if (code.substr(code.size() - 2, 2) == "35") {
            cout << "-";
        } else {
            cout << "?";
        }
        cout << endl;
    }
    
    return 0;
}
