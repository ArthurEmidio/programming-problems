#include <bits/stdc++.h>

using namespace std;

int main()
{    
    int n;
    scanf("%d", &n);
    
    vector<int> ps(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ps[i]);
    }
    getchar();
    
    bool yes = true;
    for (int i = 0; i < n; i++) {
        string line;
        
        char c;
        int vowels = 0;
        while (scanf("%c", &c) > 0) {
            if (c == '\n') break;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
                vowels++;
            }
        }
        if (vowels != ps[i]) yes = false;
    }
    
    printf("%s\n", yes ? "YES" : "NO");
    
    return 0;
}
