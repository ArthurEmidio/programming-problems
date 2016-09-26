#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll n, t;
    cin >> n >> t;
    
    string s;
    cin >> s;
    
    vector<int> integerPart(200005);
    vector<int> decimal(200005);
    
    int i;
    for (i = 0; s[i] != '.'; i++) {
        integerPart[i] += (s[i] - 48);
    }
    
    int intEnd = i - 1;
    
    i++;
    int j;
    for (j = 0; i < n; i++, j++) {
        decimal[j] += (s[i] - 48);
    }
    decimal[j] = -1;
    
    if (decimal[0] < 5) {
        for (int j = 0; t > 0 && j >= 0 && decimal[j + 1] != -1;) {
            int &num = decimal[j];
            int &next = decimal[j+1];
        
            if (next >= 5) {
                num++;
                next = -1;
                j--;
                t--;
            } else {
                j++;
            }
        }
    }

    if (decimal[0] >= 5 && t > 0) {
        int i = intEnd;
        while (integerPart[i] == 9 && i >= 0) {
            integerPart[i] = 0;
            --i;
        }
        
        if (i < 0) printf("1");
        else integerPart[i]++;       
        for (int i = 0; i <= intEnd; i++) {
            printf("%d", integerPart[i]);
        }
    } else {
        for (int i = 0; s[i] != '.'; i++) printf("%c", s[i]);
        printf(".");
        for (int i = 0; decimal[i] != -1; i++) printf("%d", decimal[i]);
    }
    printf("\n");
    
    return 0;
}
