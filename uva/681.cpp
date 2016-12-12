#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793
#define EPS 1e-7

using Point = pair<int, int>;

int D(const Point &P, const Point &Q, const Point &R)
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
    int n;
    cin >> n;
    printf("%d\n", n);
    
    while (n--) {
        int m;
        cin >> m;
        
        vector<Point> vertices(m);
        for (int i = 0; i < m; i++) {
            cin >> vertices[i].first >> vertices[i].second;
        }
        if (n > 0) {
            int usl;
            cin >> usl;
        }
        
        vector<Point> ch = convexHull(vertices);
        printf("%lu\n", ch.size() + 1);
        
        int start = 0;
        for (int i = 0; i < ch.size(); i++) {
            if (ch[i].second < ch[start].second || (ch[i].second == ch[start].second && ch[i].first < ch[start].first)) {
                start = i;
            }
        }
        
        for (int i = 0; i < ch.size(); i++) {
            int idx = (start + i) % ch.size();
            printf("%d %d\n", ch[idx].first, ch[idx].second);
        }
        printf("%d %d\n", ch[start].first, ch[start].second);
        if (n > 0) printf("-1\n");
    }
    
    return 0;
}
