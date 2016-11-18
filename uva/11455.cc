#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        ll l1, l2, l3, l4;
        cin >> l1 >> l2 >> l3 >> l4;
        
        bool isQuadrangle = (l1 + l2 + l3) > l4 && (l1 + l2 + l4) > l3 && (l1 + l3 + l4) > l2 && (l2 + l3 + l4) > l1;
        if (!isQuadrangle) {
            printf("banana");
        } else {
            bool isRectangle = (l1 == l2 && l3 == l4) || (l1 == l3 && l2 == l4) || (l1 == l4 && l2 == l3);
            if (!isRectangle) {
                printf("quadrangle");
            } else {
                bool isSquare = (l1 == l2 && l2 == l3 && l3 == l4);
                printf("%s", isSquare ? "square" : "rectangle");
            }
        }
        printf("\n");
    }
    
    return 0;
}
