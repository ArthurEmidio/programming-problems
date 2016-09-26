#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
        
    vector<int> obs(n);
    for (int i = 0; i < n; i++) {
        cin >> obs[i];
    }
    
    if (obs[n - 1] == 0) {
        printf("UP\n");
    } else if (obs[n - 1] == 15) {
        printf("DOWN\n");
    } else if (n == 1) {
        printf("-1\n");
    } else {
        int last = obs[n - 1];
        int last2 = obs[n - 2];
        bool up = last > last2;
        printf("%s\n", up ? "UP" : "DOWN");
    }
    
    return 0;
}
