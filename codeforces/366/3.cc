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
    
    int n, q;
    scanf("%d %d", &n, &q);
    
    vector<int> apps(n, 0);
    vector<int> events;
    vector<int> maxErase(n, 0);
    
    ll unread = 0;
    int maxT = 0;
    
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        
        int x;
        scanf("%d", &x);
        
        switch (type) {
            case 1:
                x--;
                
                apps[x]++;
                unread++;
                events.push_back(x);
                
                break;
            case 2:
                x--;
                
                unread -= apps[x];
                maxErase[x] = events.size();
                apps[x] = 0;
                
                break;
            case 3:
                if (x > maxT) {
                    for (int j = maxT; j < x; j++) {
                        int app = events[j];
                        if (maxErase[app] <= j) {
                            apps[app]--;
                            unread--;
                        }
                    }
                    maxT = x;
                }
            break;
        }
        
        printf("%I64d\n", unread);
    }

    return 0;
}
