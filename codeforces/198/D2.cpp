#include <bits/stdc++.h>

using namespace std;

vector<int> reconstruct(vector<int> &v, vector<int> &p)
{
    vector<int> ans;
    stack<int> s;
    int i;
    for (i = p.size() - 1; i >= 0; i = p[i]) s.push(v[i]);
    while (!s.empty()) ans.push_back(s.top()), s.pop();
    return ans;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> lis, lis_id, p(n);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        
        if (idx < lis.size()) {
            lis[idx] = v[i];
            lis_id[idx] = i;
        } else {
            lis.push_back(v[i]);
            lis_id.push_back(i);
        }
        
        p[i] = idx ? lis_id[idx - 1] : -1;
    }
    
    vector<int> x = reconstruct(v, p);
    for (int a : x) cout << a << " ";
    cout << endl;
    
    cout << lis.size() << endl;
    
    return 0;
}
