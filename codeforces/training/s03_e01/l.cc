#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    
    double penalty = 0;
    const int strSize = s.size();
    
    int ones = 0;
    for (int i = 0; i < strSize; i++) {
        if (s[i] == '1') ones++;
    }
    
    int j = strSize - ones;
    int i = j - 1;
    while (j < strSize) {
        while (j < strSize && s[j] == '1') j++;
        if (j < strSize) {
            while (s[i] != '1') i--;
            penalty += sqrt(j - i);
            j++;
            i--;
        }
    }
    
    printf("%.12lf\n", penalty);
    
    return 0;
}
