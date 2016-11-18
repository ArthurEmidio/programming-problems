#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> pc(n);
    for (int i = 0; i < n; i++) {
        cin >> pc[i];
    }
    
    vector<int> so(m);
    for (int i = 0; i < m; i++) {
        cin >> so[i];
    }
    
    sort(pc.begin(), pc.end());
    sort(so.begin(), so.end());
    
    int begin = 0;
    int end = min(pc.size(), so.size()) - 1;
    
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (pc[mid] <= so[mid]) {
            begin = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    int N = begin;
    
    
    
    return 0;
}
