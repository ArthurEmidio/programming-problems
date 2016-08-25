#include <bitset>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int even, odd;

inline int nextEven()
{
    even += 2;
    return even - 2;
}

inline int nextOdd()
{
    odd += 2;
    return odd - 2;
}

int main()
{       
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    odd = 1;
    even = 2;
                
    bool remaining = (n - 1) % 4 != 0;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int upperBound = (n == 3) ? 1 : ((n / 2));
        
    for (int i = 0; i < upperBound; i++) {            
        if (i % 2 == 0) {
            if (i == (n / 2) - 1) {
                matrix[i][n / 2] = nextOdd();
                matrix[n - i - 1][n / 2] = nextOdd();
                break;
            }
                
            for (int j = 1; j < n - 1; j++) {
                matrix[i][j] = nextOdd();
                matrix[n - i - 1][j] = nextOdd();
            }
        } else {
            matrix[i][n / 2] = nextOdd();
            matrix[n - i - 1][n / 2] = nextOdd();
                
            if (remaining) {
                matrix[i][0] = nextOdd();
                matrix[n - i - 1][0] = nextOdd();

                matrix[i][n - 1] = nextOdd();
                matrix[n - i - 1][n - 1] = nextOdd();
            }
        }
    }
                
    for (int i = 0; i < n; i++) matrix[n / 2][i] = nextOdd();
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (matrix[i][j] ? matrix[i][j] : nextEven()) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
