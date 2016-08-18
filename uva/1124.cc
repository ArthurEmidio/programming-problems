#include <iostream>

using namespace std;

int main()
{
    string aux;
    string s;
    while (getline(std::cin, aux)) {
        s += aux + '\n';
    }
    
    cout << s;
}