#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int curr = 0;

        for (int j = 0; j < n; j++) {
            string s = words[j] + words[j];
            int pos = s.find(words[i]);
            if (pos == string::npos) {
                printf("-1\n");
                return 0;
            }

            curr += pos;
        }

        ans = min(ans, curr);
    }

    printf("%d\n", ans);

    return 0;
}
