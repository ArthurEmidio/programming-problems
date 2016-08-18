#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int f(int n)
{
    int power = 10;
    int sum = 0;
    while (n > 0) {
        int digit = (n % power);
        sum += digit;
        n /= power;
        power *= 10;
    }
    
    return sum;
}

int main()
{
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        while (n > 9) {
            n = f(n);
        }
        
        cout << n << endl;
    }
    
    return 0;
}