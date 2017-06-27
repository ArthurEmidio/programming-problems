#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();

    multiset<char> oleg, igor;
    for (char c : s) {
        oleg.insert(c);
        if (oleg.size() > (n + 1)/2) oleg.erase(prev(oleg.end()));
    }

    for (char c : t) {
        igor.insert(c);
        if (igor.size() > n/2) igor.erase(igor.begin());
    }

    bool turn = true;
    int i = 0;
    int j = n - 1;
    string ans(n, 0);

    while (i < j) {
        char boleg = *oleg.begin();
        char woleg = *oleg.rbegin();
        char bigor = *igor.rbegin();
        char wigor = *igor.begin();

        if (turn) { // oleg
            char chosen;
            if (boleg >= bigor) {
                ans[j--] = woleg;
                chosen = woleg;
            } else {
                ans[i++] = boleg;
                chosen = boleg;
            }
            oleg.erase(oleg.find(chosen));
        } else { // igor
            char chosen;
            if (boleg >= bigor) {
                ans[j--] = wigor;
                chosen = wigor;
            } else {
                ans[i++] = bigor;
                chosen = bigor;
            }
            igor.erase(igor.find(chosen));
        }

        turn = !turn;
    }

    if (!oleg.empty()) ans[i] = *oleg.begin();
    if (!igor.empty()) ans[i] = *igor.begin();

    cout << ans << endl;

    return 0;
}
