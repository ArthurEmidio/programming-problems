#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793
#define EPS 1e-7

typedef long long ll;

using Point = pair<ll, ll>;

ll D(const Point &P, const Point &Q, const Point &R)
{
    return (P.first * Q.second + P.second * R.first + Q.first * R.second) - (R.first * Q.second + R.second * P.first + Q.first * P.second);
}

vector<Point> convexHull(vector<Point> &P)
{
    sort(P.begin(), P.end());
    
    vector<Point> L;
    for (const Point &p : P) {
        while (L.size() >= 2 && D(L[L.size() - 2], L[L.size() - 1], p) < 0) L.pop_back();
        L.push_back(p);
    }
    
    vector<Point> U;
    for (auto it = P.rbegin(); it != P.rend(); it++) {
        const Point &p = *it;
        while (U.size() >= 2 && D(U[U.size() - 2], U[U.size() - 1], p) < 0) U.pop_back();
        U.push_back(p);
    }
    
    L.pop_back();
    U.pop_back();
    
    L.reserve(L.size() + U.size());
    L.insert(L.end(), U.begin(), U.end());
    
    return L;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<Point> vertices;
        for (int i = 0; i < n; i++) {
            ll x, y;
            char c;
            cin >> x >> y >> c;
            if (c == 'Y') {
                vertices.push_back(Point(x,y));
            }
        }
        
        vector<Point> ch = convexHull(vertices);
        int start = 0;
        for (int i = 0; i < ch.size(); i++) {
            if (ch[i].first < ch[start].first || (ch[i].first == ch[start].first && ch[i].second < ch[start].second)) {
                start = i;
            }
        }
        
        printf("%lu\n", ch.size());
        for (int i = 0; i < ch.size(); i++) {
            int idx = (start + i) % ch.size();
            printf("%lld %lld\n", ch[idx].first, ch[idx].second);
        }
    }
    
    return 0;
}
