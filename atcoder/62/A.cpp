#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> A = {1,3,5,7,8,10,12};
    set<int> B = {4,6,9,11};
    set<int> C = {2};

    int x, y;
    cin >> x >> y;

    if ((A.count(x) && A.count(y)) || (B.count(x) && B.count(y)) || (C.count(x) && C.count(y))) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
