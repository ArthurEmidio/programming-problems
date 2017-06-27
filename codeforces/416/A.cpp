#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    bool turn = true;
    int n = 1;
    while (a >= 0 && b >= 0) {
        if (turn) a -= n;
        else b -= n;
        n++;
        turn = !turn;
    }

    printf("%s\n", a < 0 ? "Vladik" : "Valera");

    return 0;
}
