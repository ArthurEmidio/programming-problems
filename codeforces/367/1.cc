#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <map>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    
    int a, b;
    cin >> a >> b;
    
    int n;
    cin >> n;
    
    double bestTime = std::numeric_limits<double>::infinity();
    for (int i = 0; i < n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        
        double dist = hypot(x - a, y - b);
        double t = dist / v;
        bestTime = min(bestTime, t);
    }
    
    printf("%f\n", bestTime);

    return 0;
}
