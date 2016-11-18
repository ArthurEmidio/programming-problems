#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{    
    int n;
    scanf("%d", &n);
    
    set<int> nums;
    for (int i = 0; i < n; i++) {
        int y;
        scanf("%d", &y);
        nums.insert(y);
    }
    
    for (;;) {
        auto it = prev(nums.end());
        int v = *it;
        
        if (v == 1) break;
        
        do {
            v /= 2;
        } while (v > 1 && nums.count(v));
        
        if (v == 1 && nums.count(1)) break;
        
        nums.erase(it);
        nums.insert(v);
    }
    
    for (int v : nums) printf("%d ", v);
    printf("\n");
    
    return 0;
}
