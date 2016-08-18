#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

#define ll long long

int main()
{
    int count = 1;
    for (;;) {
        string input;
        getline(cin, input);
                        
        if (input.empty()) break;
        if (cin.eof()) break;
        
        int n;
        string line;
        getline(cin, line);
        istringstream iss(line);
        iss >> n;
        
        cout << "Case " << count << ":" << endl;
        
        for (int id = 0; id < n; id++) {
            string line;
            getline(cin, line);
            istringstream iss(line);
            
            int i, j;
            iss >> i >> j;
            
            int start = min(i, j);
            int end = max(i, j);
            
            char d = input[start];
            bool valid = true;
            for (int k = start + 1; k <= end; k++) {
                if (input[k] != d) {
                    valid = false;
                    break;
                }
            }
            cout << (valid ? "Yes" : "No") << endl;
        }
       
       count++; 
    }
    
    return 0;
}
