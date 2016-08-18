#include <iostream>

using namespace std;

int main()
{
    int pointPos = -1;
    
    string n;
    cin >> n;
    
    int i = 0;
    while (n[i] == '0') {
        i++;
    }
    
    int maxIndex = n.size() - 1;
    int j = n.size() - 1;
    
    if (n[j] == '.') {
        maxIndex--;
        j--;
    }
    
    while (n[j] == '0' && j > i) {
        j--;
    }
    if (n[j] == '.') {
        maxIndex = j - 1;
        j--;
    }
    while (n[j] == '0' && j > i) {
        j--;
    }

    int B = 0;
    
    bool isLessThanOne = (n[i] == '.');
    if (isLessThanOne) {
        B = -1;
        
        i++;
        while (n[i] == '0') {
            i++;
            B--;
        }    
    }
    
    cout << n[i];
        
    if (i != j) {
        cout << ".";
    }
    
    i++;
        
    if (!isLessThanOne) {
        while (i <= j && n[i] != '.') {
            cout << n[i];
            i++;
            B++;
        }
    
        if (n[i] == '.') {
            i++;
        } else {
            B += maxIndex - j;
        }
    }
    
    while (i <= j) {
        cout << n[i];
        i++;
    }
    
    if (B != 0) {
        cout << "E" << B;
    }
    
    cout << endl;    
    
    return 0;
}
