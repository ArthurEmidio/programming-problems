#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    string one = "one";
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        if (s.size() > 3) {
            cout << 3;
        } else {
            int j = 0;
            int mistakes = 0;
            while (j < 3 && mistakes <= 1) {
                if (one[j] != s[j]) mistakes++;
                j++;
            }
            if (mistakes <= 1) {
                cout << 1;
            } else {
                cout << 2;
            }
        }
        cout << endl;
    }
    
    return 0;
}
