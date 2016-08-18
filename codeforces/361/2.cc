#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int minEnergy(int target, const vector<int> &shortcuts) {
    int energy = 0;
    
    int i = 0;
    while (true) {
        if (i == target) {
            break;
        }
        
        if (i < shortcuts[i] && shortcuts[i] <= target) {
            i = shortcuts[i];
        } else {
            i++;
        }
        
        energy++;
    }

    return energy;
}

int main() {
    vector<int> shortcuts;
    
    int n;
    scanf("%d", &n);
        
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        shortcuts.push_back(curr - 1);
    }
    
    for (int i = 0; i < n; i++) {
        cout << minEnergy(i, shortcuts);
        if (i < n - 1)  cout << " ";
    }
    cout << endl;
    
    return 0;
}
