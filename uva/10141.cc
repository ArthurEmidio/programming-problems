#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <limits>

using namespace std;

int main()
{   
    for (int rfp = 1; ; rfp++) {
        int n, p;
        cin >> n >> p;
        getchar();
    
        if (n == 0 && p == 0) break;
    
        string best;
        double maxCompliance = 0;
        double price = std::numeric_limits<double>::infinity();
    
        for (int i = 0; i < n; i++) {
            string req;
            getline(cin, req);
        }
                
        for (int i = 0; i < p; i++) {
            string proposal;
            getline(cin, proposal);
        
            double d;
            int r;
        
            cin >> d >> r;
            getchar();
        
            for (int j = 0; j < r; j++) {
                string req;
                getline(cin, req);
            }
        
            double compliance = static_cast<double>(r) / n;
            if (compliance > maxCompliance || (compliance == maxCompliance && d < price)) {
                best = proposal;
                maxCompliance = compliance;
                price = d;
            }
        }
        
        if (rfp != 1) printf("\n");
        printf("RFP #%d\n%s\n", rfp, best.c_str());
    }
    
    return 0;
}
