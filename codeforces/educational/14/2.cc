#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main() {
    map<char, char> mirrorChars = {
        {'A', 'A'},
        {'b', 'd'},
        {'d', 'b'},
        {'H', 'H'},
        {'I', 'I'},
        {'M', 'M'},
        {'O', 'O'},
        {'o', 'o'},
        {'T', 'T'},
        {'U', 'U'},
        {'V', 'V'},
        {'v', 'v'},
        {'W', 'W'},
        {'w', 'w'},
        {'X', 'X'},
        {'x', 'x'},
        {'Y', 'Y'},
        {'p', 'q'},
        {'q', 'p'}
    };
    
    string str;
    cin >> str;
    
    bool isPalindrome = true;
    int n = str.size();
    for (int i = 0; i < ceil(n / 2.0); i++) {
        char ch1 = str[i];
        char ch2 = str[n - 1 - i];
        if (mirrorChars.count(ch1) > 0 && mirrorChars[ch1] == ch2) {
            continue;
        } else {
            isPalindrome = false;
            break;
        }
    }
    
    cout << (isPalindrome ? "TAK" : "NIE") << endl;
    
    return 0;
}
