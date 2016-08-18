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
    
    vector<bool> answers(n, false);
    
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        
        bool isValid = true;
        int y1, y2;
        cin >> y1 >> y2;
        int value = abs(y1 - y2);
        
        for (int j = 1; j < w; j++) {
            cin >> y1 >> y2;
            if (abs(y1 - y2) != value) {
                isValid = false;
            }
        }
        
        if (isValid) {
            answers[i] = true;
        }
    }
    
    int i = 0;
    for (bool b : answers) {
        printf("%s\n", b ? "yes" : "no");
        i++;
        if (i != n) printf("\n");
    }
    
    return 0;   
}
