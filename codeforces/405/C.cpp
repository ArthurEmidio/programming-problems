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

int main()
{
    ios_base::sync_with_stdio(false);

    vector<string> names;
    for (char i = 'A'; i <= 'Z'; i++) {
        string n1;
        n1 += i;
        names.push_back(n1);
        for (char j = 'a'; j <= 'z'; j++) {
            string n2 = n1 + j;
            names.push_back(n2);
        }
    }

    int n, k;
    cin >> n >> k;
    vector<bool> groups(n-k+1);
    for (int i = 0; i < n-k+1; i++) {
        string s;
        cin >> s;
        groups[i] = (s == "YES");
    }

    vector<string> ans(n);
    int x = 0;
    ans[n-1] = names[x++];
    for (int i = n-2; i >= n-k+1; i--) {
        ans[i] = names[x++];
    }

    for (int i = n-k; i >= 0; i--) {
        if (groups[i]) ans[i] = names[x++];
        else ans[i] = ans[i + k - 1];
    }

    for (const string &s : ans) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
