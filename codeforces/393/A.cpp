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

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int m, d;
    cin >> m >> d;

    int rem = 8 - d;
    int weeks = 1 + ((days[m-1] - rem) / 7);
    weeks += ((days[m-1] - rem) % 7) == 0 ? 0 : 1;
    cout << weeks << endl;

    return 0;
}
