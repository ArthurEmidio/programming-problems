#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

#define ll long long

int getNumber(string name)
{
    int n = 0;
    for (char c : name) {
        char cl = tolower(c);
        if (cl >= 'a' && cl <= 'z') {
            n += tolower(c) - 96;
        }
    }
    
    while (n > 9) {
        int m = n;
        n = 0;
        
        while (m != 0) {
            n += m % 10;
            m /= 10;
        }
    }
    
    return n;
}

int main()
{
    for (;;) {
        string name1;
        string name2;
        
        getline(cin, name1);
        if (cin.eof()) break;
        getline(cin, name2);
        
        double x = getNumber(name1);
        double y = getNumber(name2);
                        
        double res;
        if (x < y) {
            res = x / y;
        } else {
            res = y / x;
        }
        
        res *= 100;
        printf("%.2f %c\n", res, '%');
    }
    
    return 0;
}