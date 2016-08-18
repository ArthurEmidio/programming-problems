#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
        
    for (int i = 0; i < n; i++) {
        map<char, int> counter = {{'M', 0}, {'F', 0}};        
                
        string s;
        getline(cin, s);
        
        for (char c : s) {
            if (c == 'M' || c == 'F') counter[c]++;
        }
        
        cout << ((counter['M'] == counter['F'] && counter['M'] > 1) ? "LOOP" : "NO LOOP") << endl;
    }
    
    return 0;
}

