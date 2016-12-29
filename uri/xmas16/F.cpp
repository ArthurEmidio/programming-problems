#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<string> names(n);
    int beh = 0;
    for (int i = 0; i < n; i++) {
        char c;
        string name;
        cin >> c >> name;
        names[i] = name;
        
        if (c == '+') beh++;
    }
    
    sort(names.begin(), names.end());
    
    for (string &name : names) {
        cout << name << endl;
    }
    printf("Se comportaram: %d | Nao se comportaram: %d\n", beh, n-beh);
    
    return 0;
}