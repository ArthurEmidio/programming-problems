#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

#define ll long long

int main()
{
    while (1) {
        int dur;
        double downPayment;
        double loan;
        int records;
        
        cin >> dur >> downPayment >> loan >> records;
        if (dur < 0) break;
        
        double carPrice = downPayment + loan;
                      
        bool found = false;
        int ans = dur;
        
        double depreciation;
        int nextMonth;
        double nextDepreciation;
        cin >> nextMonth >> nextDepreciation;
        
        int readFromInput = 1;
        for (int month = 0; month <= dur; month++) {
            if (month == nextMonth) {
                depreciation = nextDepreciation;
                if (readFromInput < records) {
                    cin >> nextMonth >> nextDepreciation;
                    readFromInput++;
                } else {
                    nextMonth = dur;
                }
            }
            
            carPrice = carPrice - (carPrice * depreciation);
            
            double owns = loan - (month * (loan / dur));            
            if (!found && owns < carPrice) {
                ans = month;
                found = true;
            }
        }
        
        printf("%d month%s\n", ans, ans != 1 ? "s" : "");
    }
        
    return 0;
}
