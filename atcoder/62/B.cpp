#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i];
    }

    for (int i = 0; i < m + 2; i++) cout << '#';
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << '#' << lines[i] << '#' << endl;
    }
    for (int i = 0; i < m + 2; i++) cout << '#';
    cout << endl;

    return 0;
}
