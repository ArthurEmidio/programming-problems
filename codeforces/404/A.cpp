#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> m = {{"Tetrahedron", 4}, {"Cube", 6}, {"Octahedron", 8}, {"Dodecahedron", 12}, {"Icosahedron", 20}};

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ans += m[s];
    }

    cout << ans << endl;

    return 0;
}
