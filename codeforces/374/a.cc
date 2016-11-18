#include <iostream>
#include <vector>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int group = 0;
    vector<int> res;
    for (char c : s) {
        if (c == 'B') {
            group++;
        } else {
            if (group) res.push_back(group);
            group = 0;
        }
    }
    if (group) {
        res.push_back(group);
    }
    
    cout << res.size() << endl;
    for (int i : res) {
        printf("%d ", i);
    }
    if (!res.empty()) printf("\n");
    
    return 0;
}
