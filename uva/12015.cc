#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int main()
{    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<string> top;
        int highestRank = 0;
        
        for (int j = 0; j < 10; j++) {
            string url;
            int rank;
            cin >> url >> rank;
            
            if (rank > highestRank) {
                highestRank = rank;
                top.clear();
                top.push_back(url);
            } else if (rank == highestRank) {
                top.push_back(url);
            }
        }
        
        cout << "Case #" << i + 1 << ":" << endl;
        for (string url : top) {
            cout << url << endl;
        }
    }
        
    return 0;
}