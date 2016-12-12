#include <bits/stdc++.h>

using namespace std;

int main()
{
    string u;
    cin >> u;
    
    set<char> chars;
    for (char c : u) {
        chars.insert(c);
    }
    
    printf("%s\n", chars.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
    
    return 0;
}