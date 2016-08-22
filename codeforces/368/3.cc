#include <iostream>
#include <limits>
#include <cmath>
#include <sstream>
#include <vector>
#include <set>
#include <map>

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

#define ll long long
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    
    double theta;
    bool got = false;
    for (theta = 0; theta <= 90; theta += 0.0001) {
        double thetaRad = (theta * PI) / 180;
        
        double sinRes = sin(thetaRad);
        double y = n * sinRes;
                        
        int roundedY = round(y);
        double temptY = sqrt(pow(n, 2) - pow(roundedY, 2));
        int temptIntY = temptY;
                
        if (fabs(temptY - temptIntY) <= EPS && roundedY != n && roundedY != 0) {
            cout << min(temptIntY, roundedY) << " " << max(temptIntY, roundedY) << endl;
            got = true;
            break;
        }
        
        double x = n / sinRes;        
               
        int roundedX = round(x);
        double tempt = sqrt(pow(roundedX, 2) - pow(n, 2));
        
        // if ((int) theta == 53) {
        //     cout << theta << ": " << tempt << endl;
        // }
        
        int temptInt = tempt;
                
        if (fabs(tempt - temptInt) <= EPS && roundedX != n && roundedX != 0) {
            cout << temptInt << " " << roundedX << endl;
            got = true;
            break;
        }
    }
    
    if (!got) {
        cout << "-1" << endl;
    }

    return 0;
}
    