#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    if (n == 3) {
        printf("1\n3\n");
    } else if (n % 2 == 0) {
        int ans = n/2;
        printf("%d\n", ans);
        for (int i = 0; i < ans; i++) printf("2 ");
        printf("\n");
    } else {
        n -= 3;
        int ans = n/2;
        printf("%d\n", ans + 1);
        for (int i = 0; i < ans; i++) printf("%d ", 2);
        printf("3\n");        
    }
    
    return 0;
}
