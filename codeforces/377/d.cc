#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

map<pair<int, bitset<100000>> dp;
int n, m;
vector<int> days;
vector<int> exams;

int solve(int day, bitset<100000> bs)
{
    auto p = make_pair(day, bs);
    if (dp.count(p)) return dp.value(p);
    
    
    
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < m; i++) {
        if (!bs.test(i)) {
            bs.flip(i);
            ans = min(ans, solve(day + 1, bs));
            bs.flip(i);
        }
    }
    
    return dp[p] = ans;  
}

int main()
{
    cin >> n >> m;
    
    int day;
    for (int i = 0; i < n; i++) {
        cin >> day;
        days.push_back(day);
    }
    
    int exam;
    for (int i = 0; i < m; i++) {
        cin >> exam;
        exams.push_back(exam);
    }
    
    bitset<100000> bs;
    bs.set();
    
    int ans = solve(0, bs);
    printf("%d\n", ans == numeric_limits<int>::max() ? -1 : ans);
        
    return 0;
}
