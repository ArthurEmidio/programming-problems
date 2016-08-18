#include <iostream>
#include <string>

using namespace std;

#define ll long long

void toDecimal(const string &n)
{
    ll b = 0;
    
    ll i = n.size() - 1;
    ll currPwrTen = 1;
    
    while (n[i] != 'e') {
        ll digit = n[i] - 48;
        b += digit * currPwrTen;
        currPwrTen *= 10;
        i--;
    }
    
    0.3e1
    
    ll zerosStartIdx = i;
    if (n[i - 1] == '0') {
        zerosStartIdx = i - 1;
        while (n[zerosStartIdx] == '0' || n[zerosStartIdx] == '.') {
            zerosStartIdx--;
        }
        if (n[zerosStartIdx + 1] == '.') {
            zerosStartIdx++;
        }
    }
    
    if (b == 0) {
        i = 0;
        if (i >= zerosStartIdx) {
            cout << '0';
        } else {
            while (i < zerosStartIdx) {
                cout << n[i];
                i++;
            }
        }
        return;
    }
    
    int j = 0;
    int k = 0;
    
    if (n[0] == '0') {
        k += 2;
        j++;
        while (j <= b && n[k] == '0') {
            j++;
            k++;
        }
        
        cout << n[k];
        j++;
        k++;
    } else {
        cout << n[k];
        j++;
        k++;
                
        while (j <= b && n[k] != '.') {
            cout << n[k];
            k++;
        }
    
        k++;
    
        while (j <= b && n[k] != 'e') {
            cout << n[k];
            j++;
            k++;
        }
    }
             
    if (j >= b + 1 && k < zerosStartIdx && n[k] != 'e') {
        cout << ".";
        
        while (n[k] != 'e' && k < zerosStartIdx) {
            if (n[k] != '.') {
                cout << n[k];
            }
            k++;
        }
    } else {
        while (j <= b) {
            cout << '0';
            j++;
        }
    }
}

int main()
{
    string n;
    cin >> n;
    
    toDecimal(n);
    cout << endl;
        
    return 0;
}
