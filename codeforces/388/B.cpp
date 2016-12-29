#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second

typedef long long ll;
typedef vector<int> vi;

using Point = pair<int,int>;

int main()
{
    ios_base::sync_with_stdio(false);
    
    Point A, B, C;
    cin >> A.ff >> A.ss >> B.ff >> B.ss >> C.ff >> C.ss;
    
    Point d1(A.ff - (B.ff - C.ff), A.ss - (B.ss - C.ss));
    Point d2(B.ff - (C.ff - A.ff), B.ss + (A.ss - C.ss));
    Point d3(C.ff + (B.ff - A.ff), C.ss - (A.ss - B.ss));
    
    cout << 3 << endl;
    cout << d1.ff << " " << d1.ss << endl;
    cout << d2.ff << " " << d2.ss << endl;
    cout << d3.ff << " " << d3.ss << endl;
    
    return 0;
}
