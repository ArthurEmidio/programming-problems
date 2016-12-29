#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;  
    cin >> n;
    getchar();
    
    map<string, string> greetings;
    for (int i = 0; i < n; i++) {
        string lang, msg;
        getline(cin, lang);
        getline(cin, msg);
        greetings[lang] = msg;
    }
    
    int m;
    cin >> m;
    getchar();
    
    for (int i = 0; i < m; i++) {
        string name, lang;
        getline(cin, name);
        getline(cin, lang);
        cout << name << endl << greetings[lang] << endl << endl;
    }
    
    return 0;
}