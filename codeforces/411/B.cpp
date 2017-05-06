#include <bits/stdc++.h>

using namespace std;

int main()
{
    const string pattern = "aabb";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        printf("%c", pattern[i % pattern.size()]);
    }
    printf("\n");

    return 0;
}
