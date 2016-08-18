#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        
        int maxSal = max(max(s1, s2), s3);
        int minSal = min(min(s1, s2), s3);
        int survSal = (s1 + s2 + s3) - maxSal - minSal;
        cout << "Case " << i + 1 << ": " << survSal << endl;
    }
    
    return 0;
}
