#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    int caseN = 1;
    
    while (1) {
        int n, m, c;
        cin >> n >> m >> c;
        
        if (n == 0 && m == 0 && c == 0) {
            break;
        }
        
        vector<pair<int, bool>> turnedOn;
        for (int i = 0; i < n; i++) {
            int ci;
            cin >> ci;
            turnedOn.push_back(make_pair(ci, false));
        }
        
        int consumption = 0;
        int maxConsumption = 0;
        
        for (int i = 0; i < m; i++) {
            int t;
            cin >> t;
            t--;
            turnedOn[t].second = !turnedOn[t].second;
            
            if (turnedOn[t].second) {
                consumption += turnedOn[t].first;
            } else {
                consumption -= turnedOn[t].first;
            }
            
            maxConsumption = max(consumption, maxConsumption);
        }
        
        cout << "Sequence " << caseN << endl;
        if (maxConsumption > c) {
            cout << "Fuse was blown." << endl;
        } else {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << maxConsumption << " amperes." << endl;
        }
        cout << endl;
        
        caseN++;
    }
    
    return 0;
}