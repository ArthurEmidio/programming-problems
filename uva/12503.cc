#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        int p = 0;
        vector<int> history;
        for (int j = 0; j < n; j++) {
            string instr;
            cin >> instr;
            
            if (instr == "SAME") {
                cin >> instr;
                int ref;
                cin >> ref;
                instr = history[ref - 1] == 0 ? "LEFT" : "RIGHT";
            }
            
            if (instr == "LEFT") {
                p--;
                history.push_back(0);
            } else {
                p++;
                history.push_back(1);
            }
        }
        
        cout << p << endl;
    }
    
    return 0;
}
