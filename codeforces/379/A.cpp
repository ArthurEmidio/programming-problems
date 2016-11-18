#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int danik = 0;
    int anton = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'D') danik++;
        else anton++;
    }
    
    if (danik == anton) {
        printf("Friendship\n");
    } else if (danik > anton) {
        printf("Danik\n");
    } else {
        printf("Anton\n");
    }
    
    return 0;
}