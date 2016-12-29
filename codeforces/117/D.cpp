#include <bits/stdc++.h>

using namespace std;

bool doesGenerate(int i, const string &s, const string &t)
{
    for (int j = 0; j < t.size(); j++) {
        if (t[j] != s[j % i]) return false;
    }
    return true;
}

int solve(const string &s, const string &t)
{
    int ans = 0;
    const int n = s.size();
    const int m = t.size();
    
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            int k = n/i;
            if (k <= m && m % k == 0 && doesGenerate(k, s, s) && doesGenerate(k, s, t)) {
                ans++;
            }
            if (i != k && i <= m && m % i == 0 && doesGenerate(i, s, s) && doesGenerate(i, s, t)) {
                ans++;
            }
        }
    }
    
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    if (s2.size() > s1.size()) swap(s1, s2);
    int ans = solve(s1, s2);
    cout << ans << endl;
        
    return 0;
}