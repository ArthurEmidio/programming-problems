#include <bits/stdc++.h>

using namespace std;

int x, y;

int solve(int X, int Y, int K)
{   
    if (K == 0) return 0;
        
    int x0 = X - K;
    int y0 = Y - K;
    int x1 = X + K;
    int y1 = Y + K;
    int isInside = x >= x0 && y >= y0 && x <= x1 && y <= y1;
    
    int xNewPos = x < X ? X-K : X+K;
    int yNewPos = y < Y ? Y-K : Y+K;
     
    return isInside + solve(xNewPos, yNewPos, K/2);
}

int main()
{
    for (;;) {
        int k;
        cin >> k >> x >> y;
        if (!k && !x && !y) break;
        printf("% 3d\n", solve(1024, 1024, k));
    }
    
    return 0;
}