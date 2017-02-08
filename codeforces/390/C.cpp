#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)

typedef long long ll;
typedef vector<int> vi;

set<int> getPossible(const string &msg, vector<string> &people)
{    
    set<int> ans;
    for (int i = 0; i < people.size(); i++) ans.insert(i);
    
    for (int i = 0; i < people.size(); i++) {
        int occ = -1;
        for (;;) {
            occ = msg.find(people[i], 1 + occ);
            if (occ == string::npos) break;
            if ((occ == 0 || !isalnum(msg[occ-1])) && (occ == msg.size()-1 || !isalnum(msg[occ+people[i].size()]))) {
                ans.erase(i);
                break;
            }
        }
    }
    
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<string> people(n);
    map<string, int> peopleMap;
    peopleMap["?"] = -1;
    
    for (int i = 0; i < n; i++) {
        cin >> people[i];
        peopleMap[people[i]] = i;
    }
    
    int m;
    cin >> m;
    getchar();
    
    vector<pair<int, string>> msgs(m);
    vector<set<int>> possible(m);
    
    for (int i = 0; i < m; i++) {
        string msg;
        getline(cin, msg);
                
        int j = 0;
        string user;
        while (msg[j] != ':') user += msg[j++];
        j++;
        
        msg = msg.substr(j);
        msgs[i] = mp(peopleMap[user], msg);
        possible[i] = (msgs[i].ff == -1) ? getPossible(msg, people) : set<int>({msgs[i].ff});
    }
        
    for (int i = 0; i < m-1; i++) {
        if (possible[i].size() == 1) possible[i+1].erase(*possible[i].begin());
    }
    for (int i = m-1; i > 0; i--) {
        if (possible[i].size() == 1) possible[i-1].erase(*possible[i].begin());
    }
    
    bool valid = true;
    int prev = -1;
    for (int i = 0; i < m; i++) {
        if (possible[i].empty()) {
            valid = false;
            break;
        }
        
        msgs[i].ff = *possible[i].begin();
        if (msgs[i].ff == prev) msgs[i].ff = *next(possible[i].begin());
        prev = msgs[i].ff;
    }
    
    if (!valid) {
        cout << "Impossible" << endl;
    } else {
        for (int i = 0; i < m; i++) {
            cout << people[msgs[i].ff] << ":" << msgs[i].ss << endl;
        }
    }
}

int main()
{    
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
