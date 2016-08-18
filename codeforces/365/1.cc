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
    int n;
    cin >> n;
    
    int mishka = 0;
    int chris = 0;
    for (int i = 0; i < n; i++) {
        int m, c;
        cin >> m >> c;
        
        if (m > c) {
            mishka++;
        } else if (m < c) {
            chris++;
        }
    }
    
    if (mishka > chris) {
        cout << "Mishka";
    } else if (mishka < chris) {
        cout << "Chris";
    } else {
        cout << "Friendship is magic!^^";
    }
    cout << endl;
    
    return 0;
}
