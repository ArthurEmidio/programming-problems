#include <bits/stdc++.h>

using namespace std;

#define oo 0x3f3f3f3f3f3f3f3f
#define EPS 1e-6
#define PI 3.14159265358979323846
#define ff first
#define ss second
#define mp(i,j) make_pair(i,j)
#define ii pair<int,int>

typedef long long ll;
typedef vector<int> vi;

char board[4][4];

bool checkRow(int i)
{
    return board[i][1] == 'x' && board[i][2] == 'x' && (board[i][0] == 'x' || board[i][3] == 'x');
}

bool checkCol(int i)
{
    return board[1][i] == 'x' && board[2][i] == 'x' && (board[0][i] == 'x' || board[3][i] == 'x');
}

int checkDiag(int i, int j, bool opt, set<ii> &vis)
{
    if (i < 0 || j < 0 || i >= 4 || j >= 4) return 0;
    if (vis.count({i,j})) return 0;
    vis.insert({i,j});
    
    if (board[i][j] == 'x') {
        return 1 + ((opt) ? checkDiag(i+1, j+1, opt, vis) : checkDiag(i+1, j-1, opt, vis));
    }
    
    return 0;
}

bool possible()
{
    for (int i = 0; i < 4; i++) {
        if (checkRow(i)) return true;
        if (checkCol(i)) return true;
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 'x') {
                set<ii> vis1;
                int a = checkDiag(i, j, true, vis1);
                
                set<ii> vis2;
                int b = checkDiag(i, j, false, vis2);
                
                if (a >= 3 || b >= 3) return true;
            }
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == '.') {
                board[i][j] = 'x';
                if (possible()) {
                    cout << "YES" << endl;
                    return 0;
                }
                board[i][j] = '.';
            }
        }
    }
    
    cout << "NO" << endl;
    
    return 0;
}
