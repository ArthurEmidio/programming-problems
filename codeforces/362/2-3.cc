#include <iostream>

using namespace std;

#define ll long long

void printAsDecimal(const string &n)
{
    int b = 0;
    int powerTen = 1;
    
    int i = n.size() - 1;
    while (n[i] != 'e') {
        b += (n[i] - 48) * powerTen;
        powerTen *= 10;
        i--;
    }
    i--;
    
    int firstZeroIdx = -1;
    while ((n[i] == '0' || n[i] == '.') && i >= 0) {
        i--;
    }
    if (n[i] == '0') {
        firstZeroIdx = i;
    } else {
        firstZeroIdx = i + 1;
    }
    
    i = 0;
    while (n[i] != '.') {
        cout << n[i];
        i++;
    }
    i++;
    
    int j = 0;
    while (n[i] != 'e' && j < b) {
        cout << n[i];
        i++;
        j++;
    }
        
    if (j == b && n[i] != 'e' && i < firstZeroIdx) {
        cout << '.';
        while (n[i] != 'e') {
            cout << n[i];
            i++;
        }
    } else {
        while (j < b) {
            cout << '0';
            j++;
        }
    }
    
    cout << endl;
}

int main()
{
    string n;
    cin >> n;
    
    printAsDecimal(n);
    
    return 0;
}
