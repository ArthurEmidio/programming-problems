#include <iostream>

using namespace std;

int main()
{
    string aux;
    string s;
    while (getline(std::cin, aux)) {
        s += aux + '\n';
    }
    
    bool shouldOpen = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '"') {
            cout << s[i];
        } else {
            if (shouldOpen) {
                cout << "``";
            } else {
                cout << "''";
            }
            shouldOpen = !shouldOpen;
        }
    }
        
    return 0;
}
