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
    
    int red = 0;
    int black = 0;
    
    int wrongRed0 = 0; // starting at black
    int wrongBlack0 = 0; // starting at black
    int wrongRed1 = 0; // starting at red
    int wrongBlack1 = 0; // starting at red
    
    char curr0 = 'b';
    char curr1 = 'r';
    
    for (char c : s) {
        if (c == 'b') {
            black++;
            if (curr0 != c) wrongBlack0++;
            if (curr1 != c) wrongBlack1++;
        } else {
            red++;
            if (curr0 != c) wrongRed0++;
            if (curr1 != c) wrongRed1++;
        }
        
        swap(curr0, curr1);
    }
    
    int wrongRed, wrongBlack;
    if (wrongRed0 + wrongBlack0 < wrongRed1 + wrongBlack1) {
        wrongRed = wrongRed0;
        wrongBlack = wrongBlack0;
    } else {
        wrongRed = wrongRed1;
        wrongBlack = wrongBlack1;
    }
    
    int turns = min(wrongRed, wrongBlack) + abs(wrongBlack - wrongRed);
    printf("%d\n", turns);
    
    return 0;
}
