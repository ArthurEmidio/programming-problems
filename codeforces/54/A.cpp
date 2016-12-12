#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    queue<char> hello;
    hello.push('h'), hello.push('e'), hello.push('l'), hello.push('l'), hello.push('o');
    
    bool ans = false;
    for (char c : s) {
        if (hello.front() == c) hello.pop();
        if (hello.empty()) {
            ans = true;
            break;
        }
    }
    
    printf("%s\n", ans ? "YES" : "NO");
    
    return 0;
}