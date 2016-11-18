#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    
    vector<string> pws(n);
    vector<int> lengths(105, 0);
    vector<int> v(105, 0);
    
    for (int i = 0; i < n; i++) {
        string pw;
        cin >> pw;
        lengths[pw.size()]++;
    }
    
    for (int i = 1; i < 105; i++) {
        v[i] = lengths[i - 1] + v[i - 1];
    }
    
    string correct;
    cin >> correct;
        
    int corrSize = correct.size();
    int best = (v[corrSize] + 1) + (v[corrSize] / k)*5;
    int worst = v[corrSize + 1] + ((v[corrSize + 1]-1) / k)*5;
    
    printf("%d %d\n", best, worst);
    
    return 0;
}
