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
        
        int totPlanMile = 0;
        int totPlanJuice = 0;
        
        for (int j = 0; j < n; j++) {
            int d;
            cin >> d;
            totPlanMile += ((d / 30) + 1) * 10;
            totPlanJuice += ((d / 60) + 1) * 15;
        }
        
        cout << "Case " << i + 1 << ": ";
        if (totPlanMile < totPlanJuice) {
            cout << "Mile " << totPlanMile << endl;
        } else if (totPlanMile > totPlanJuice) {
            cout << "Juice " << totPlanJuice << endl;
        } else {
            cout << "Mile Juice " << totPlanJuice << endl;
        }
    }
    
    return 0;
}