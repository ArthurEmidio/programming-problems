#include <bits/stdc++.h>

using namespace std;

int solve1(const vector<int> &jiro, const vector<int> &ciel)
{   
    int i = 0, j = ciel.size() - 1;
    
    int ans = 0;
    while (i < jiro.size() && j >= 0) {
        if (ciel[j] >= jiro[i]) {
            ans += ciel[j--] - jiro[i++];
        } else break;
    }
    
    return ans;
}

int solve2(const vector<int> &jiro, const vector<int> &jiroD, const vector<int> &ciel)
{
    if (ciel.size() <= jiro.size() + jiroD.size()) return -1;
    
    set<int> removed;
    
    for (int i = 0, j = 0; i < jiroD.size(); i++) {
        while (j < ciel.size() && ciel[j] <= jiroD[i]) j++;
        if (j == ciel.size()) return -1;
        removed.insert(j++);
    }
    
    vector<int> newCiel;
    for (int i = 0; i < ciel.size(); i++) {
        if (!removed.count(i)) newCiel.push_back(ciel[i]);
    }
    
    int ans = 0;
    int j = 0;
    for (int i = 0; i < jiro.size(); i++) {
        while (j < newCiel.size() && newCiel[j] < jiro[i]) ans += newCiel[j++];
        if (j == ciel.size()) return -1;
        
        ans += newCiel[j] - jiro[i];
        j++;
    }
    
    while (j < newCiel.size()) ans += newCiel[j++];
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> jiroD;
    vector<int> jiro;
    
    for (int i = 0; i < n; i++) {
        string tp;
        int strength;
        cin >> tp >> strength;
        
        if (tp == "ATK") jiro.push_back(strength);
        else jiroD.push_back(strength);
    }
    
    vector<int> ciel(m);
    for (int i = 0; i < m; i++) cin >> ciel[i];
    
    sort(jiro.begin(), jiro.end());
    sort(jiroD.begin(), jiroD.end());
    sort(ciel.begin(), ciel.end());
                
    cout << max(solve1(jiro, ciel), solve2(jiro, jiroD, ciel)) << endl;
    
    return 0;
}
