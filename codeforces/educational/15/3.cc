#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> cities;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cities.push_back(a);
    }
    
    vector<int> towers;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        towers.push_back(b);
    }

    int i = 0;    
    int j = 0;
    int r = 0;
        
    while (i < m && j < n) {
        int dist = abs(cities[j] - towers[i]);
        
        int k = i + 1;
        while (k < m) {
            int d = abs(cities[j] - towers[k]);
            if (d <= dist) {
                dist = d;
                k++;
            } else {
                break;
            }
        }
        k--;
        
        r = max(dist, r);
        if (k == i) {
            j++;
        } else {
            i = k;
        }      
    }
         
    for (int k = j; k < n; k++) {
        r = max(abs(cities[k] - towers[i]), r);
    }
    
    cout << r << endl;
    
    return 0;
}
