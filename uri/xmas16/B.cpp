#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{    
    int p, a;
    cin >> p >> a;
    
    vector<ll> costs(p);
    for (int i = 0; i < p; i++) cin >> costs[i];
    
    sort(costs.begin(), costs.end());
    
    vector<list<ll>> workers(a);
    for (ll x : costs) workers[a-1].push_back(x);
    
    bool changed = false;
    int i = a-1;
    while (i > 0 || changed) {
        if (i == 0) {
            i = a-1;
            changed = false;
        }
        
        list<ll> &curr = workers[i];
        list<ll> &prev = workers[i-1];
        
        ll currSum = 0, prevSum = 0;
        ll nCurr = curr.size(), nPrev = prev.size();
        for (ll x : curr) currSum += x;
        for (ll x : prev) prevSum += x;
        
        while (!curr.empty()) {
            ll old = currSum*nCurr + prevSum*nPrev;
            
            ll front = curr.front(); curr.pop_front();
            currSum -= front;
            nCurr--;
            
            prev.push_back(front);
            prevSum += front;
            nPrev++;
            
            if (currSum*nCurr + prevSum*nPrev > old) {
                curr.push_front(front);
                currSum += front;
                nCurr++;
                
                prev.pop_back();
                prevSum -= front;
                nPrev--;
                break;
            }
            
            changed = true;
        }
        
        i--;
    }
    
    ll ans = 0;
    for (list<ll> &l : workers) {
        ll sum = 0;
        for (ll x : l) sum += x;
        ans += sum * l.size();
    }

    printf("%lld\n", ans);
    
    return 0;
}
