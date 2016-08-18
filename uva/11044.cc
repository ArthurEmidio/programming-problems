#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int m, n;
        cin >> m >> n;
        printf("%.0f\n", ceil((m - 2) / 3.0) * ceil((n - 2) / 3.0));
    }
    
    return 0;
}
