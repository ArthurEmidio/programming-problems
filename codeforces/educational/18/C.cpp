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

bool check(int x, int y)
{
    if (y == 1) return x == 1 || x == 4 || x == 7;
    return x == 2 || x == 5 || x == 8;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int sum = 0;
    bool zero = false;
    for (char c : s) {
        sum += (c - '0');
        if (c == '0') zero = true;
    }

    int n = s.size();
    int rem = sum % 3;

    int pos1 = -1;
    int r1 = -1, r2 = -1;

    if (rem) {
        for (int i = n-1; i >= 0; i--) {
            int digit = s[i] - '0';
            if (digit % 3 == 0) continue;

            if (check(digit, rem)) pos1 = (pos1 == -1) ? i : pos1;
            else if (r1 == -1) r1 = i;
            else if (r2 == -1) r2 = i;
        }
    }

    string ans;
    int mi = INT_MAX;

    if (!rem) {
        ans = s;
        mi = 0;
    }

    if (pos1 != -1) {
        string s2 = s;
        s2.erase(s2.begin() + pos1);
        int rem = 1;
        while (rem-1 < s2.size() && s2[rem-1] == '0') rem++;
        if (rem > 1) s2.erase(s2.begin(), s2.begin() + (rem-1));

        if (rem < mi) mi = rem, ans = s2;
    }

    if (r1 != -1 && r2 != -1) {
        string s3 = s;
        s3.erase(s3.begin() + r1);
        s3.erase(s3.begin() + r2);

        int rem = 2;
        while (rem-2 < s3.size() && s3[rem-2] == '0') rem++;
        if (rem > 2) s3.erase(s3.begin(), s3.begin() + (rem-2));

        if (rem < mi) mi = rem, ans = s3;
    }

    if (zero) {
        if (n-1 < mi) ans = "0", mi = n-1;
    }

    if (ans.empty()) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
