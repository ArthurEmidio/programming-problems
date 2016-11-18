#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;

int main()
{
    ios_base::sync_with_stdio(false);
    
    auto cmp = [](const ii &p1, const ii &p2) {
        return p1.second > p2.second;
    };
    
    ll n, k, x;
    scanf("%lld %lld %lld", &n, &k, &x);
    
    ll neg = 0;
    vector<ii> numbers(n);
    vector<bool> signs(n);
    for (ll i = 0; i < n; i++) {
        ll d;
        scanf("%lld", &d);
        if (d < 0) ++neg;
        numbers[i] = make_pair(i, abs(d));
        signs[i] = (d >= 0);
    }
    
    bool increase = (neg % 2 != 0);
    make_heap(numbers.begin(), numbers.end(), cmp);
    while (k--) {
        ii smallest = numbers.front();
        if (increase) {
            smallest.second += x;
        } else {
            smallest.second -= x;
            if (smallest.second <= 0) {
                increase = true;
                smallest.second *= -1;
                signs[smallest.first] = !signs[smallest.first];
            }
        }
        
        pop_heap(numbers.begin(), numbers.end(), cmp); numbers.pop_back();
        numbers.push_back(smallest); push_heap(numbers.begin(), numbers.end(), cmp);
    }
    
    sort(numbers.begin(), numbers.end(), [](const ii &p1, const ii &p2) {
        return p1.first <= p2.first;
    });

    for (ll i = 0; i < n; i++) {
        printf("%lld ", signs[i] ? numbers[i].second : -numbers[i].second);
    }
    printf("\n");
    
    return 0;
}
