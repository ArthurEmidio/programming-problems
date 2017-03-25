#include <bits/stdc++.h>

using namespace std;

int trie[1000005][27];
int curr = 1;

void insert(const string &s)
{
    int i = 0;
    for (char c : s) {
        int &nxt = trie[i][c - 'a'];
        if (!nxt) nxt = curr++;
        i = nxt;
    }
    trie[i][26] = 1;
}

int keystrokes(const string &s)
{
    int ans = 1, i = trie[0][s[0] - 'a'];
    for (int k = 1; k < s.size(); k++) {
        int q = 0;
        for (int j = 0; j < 27; j++) if (trie[i][j]) q++;
        if (q > 1) ans++;
        i = trie[i][s[k] - 'a'];
    }

    return ans;
}

int main()
{
    int n;
    while (cin >> n) {
        memset(trie, 0, sizeof trie);

        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
            insert(words[i]);
        }

        int quant = 0;
        for (const string &s : words) quant += keystrokes(s);
        printf("%.2lf\n", quant/(double)n);

        curr = 1;
    }

    return 0;
}
