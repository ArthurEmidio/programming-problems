#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define oo MAX_INT

typedef pair<int, int> ii;
typedef pair<ii, char> piece;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    
    ii king;
    scanf("%d %d", &king.ff, &king.ss);
    
    pair<int, char> top(0, 0), bottom(0, 0), left(0, 0), right(0, 0);
    pair<int, char> lt(0, 0), lb(0, 0), rt(0, 0), rb(0, 0);
    
    for (int i = 0; i < n; i++) {
        piece p;
        getchar();
        scanf("%c %d %d", &p.ss, &p.ff.ff, &p.ff.ss);
        
        int x = p.ff.ff;
        int y = p.ff.ss;
        
        if (x == king.ff) { // same col
            if (king.ss > y) { // top
                if (top.ss == 0 || top.ff < y) {
                    top.ff = y;
                    top.ss = p.ss;
                }
            } else { // bottom
                if (bottom.ss == 0 || bottom.ff > y) {
                    bottom.ff = y;
                    bottom.ss = p.ss;
                }
            }
        } else if (y == king.ss) { // same row
            if (king.ff > x) { // left
                if (left.ss == 0 || left.ff < x) {
                    left.ff = x;
                    left.ss = p.ss;
                }
            } else { // right
                if (right.ss == 0 || right.ff > x) {
                    right.ff = x;
                    right.ss = p.ss;
                }
            }
        } else if (abs(y - king.ss) == abs(x - king.ff)) { // diagonal
            if (x < king.ff) { // left
                if (y < king.ss) { // top
                    if (lt.ss == 0 || lt.ff < x) {
                        lt.ff = x;
                        lt.ss = p.ss;
                    }
                } else { // bottom
                    if (lb.ss == 0 || lb.ff < x) {
                        lb.ff = x;
                        lb.ss = p.ss;
                    }
                }
            } else { // right
                if (y < king.ss) { // top
                    if (rt.ss == 0 || rt.ff > x) {
                        rt.ff = x;
                        rt.ss = p.ss;
                    }
                } else { // bottom
                    if (rb.ss == 0 || rb.ff > x) {
                        rb.ff = x;
                        rb.ss = p.ss;
                    }
                }
            }
        }
    }
    
    if (top.ss == 'R' || top.ss == 'Q' || right.ss == 'R' || right.ss == 'Q' ||
        bottom.ss == 'R' || bottom.ss == 'Q' || left.ss == 'R' || left.ss == 'Q' ||
        lt.ss == 'B' || lt.ss == 'Q' || rt.ss == 'B' || rt.ss == 'Q' || 
        lb.ss == 'B' || lb.ss == 'Q' || rb.ss == 'B' || rb.ss == 'Q') {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}