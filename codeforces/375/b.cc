#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    bool isInsideParen = false;
    int wordsQuant = 0;
    int longestWordOutParen = 0;
    
    int currWordLength = 0;
    for (char c : s) {
        if (currWordLength && (c == '_' || c == '(' || c == ')')) {
            if (isInsideParen) wordsQuant++;
            currWordLength = 0;
        }
        
        if (c == ')') isInsideParen = false;
        else if (c == '(') isInsideParen = true;
        
        if (c != '_' && c != '(' && c != ')') {
            currWordLength++;
            if (!isInsideParen) longestWordOutParen = max(currWordLength, longestWordOutParen);
        }
    }
    
    printf("%d %d\n", longestWordOutParen, wordsQuant);
    
    return 0;
}
