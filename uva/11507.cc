#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <limits>

using namespace std;

enum Direction {
    P_X, M_Y, M_X, P_Y, M_Z, P_Z    
};

string dirToStr(Direction d)
{
    switch (d) {
        case M_X:
            return "-x";
        case P_X:
            return "+x";
        case M_Y:
            return "-y";
        case P_Y:
            return "+y";
        case M_Z:
            return "-z";
        case P_Z:
            return "+z";
    }
    return "";
}

int main()
{
    for (;;) {
        int l;
        cin >> l;
        if (l == 0) break;
        
        Direction dir = P_X;
        for (int i = l - 1; i >= 1; i--) {
            string com;
            cin >> com;
            
            Direction mov;
            if (com != "No") {
                bool isY = false;
                bool isZ = false;
                
                if (com == "+y") {
                   mov = P_Y;
                   isY = true;
                } else if (com  == "-y") {
                    mov = M_Y;
                    isY = true;
                } else if (com == "+z") {
                    mov = P_Z;
                    isZ = true;
                } else if (com == "-z") {
                    mov = M_Z;
                    isZ = true;
                }
                
                if (((dir == M_Y || dir == P_Y) && !isY) || ((dir == M_Z || dir == P_Z) && !isZ)) {
                    continue;
                }
                
                if (dir == P_X) {
                    dir = mov;
                } else if (dir == M_X) {
                    if (mov == P_X) {
                        dir = M_X;
                    } else if (mov == M_X) {
                        dir = P_X;
                    } else if (mov == P_Y) {
                        dir = M_Y;
                    } else if (mov == M_Y) {
                        dir = P_Y;
                    } else if (mov == P_Z) {
                        dir = M_Z;
                    } else if (mov == M_Z) {
                        dir = P_Z;
                    }
                } else if (mov == dir) {
                    dir = M_X;
                } else {
                    dir = P_X;
                }
                
            }
        }
        
        cout << dirToStr(dir) << endl; 
    }
    
    return 0;
}

// else if (dir == P_Z) {
//                     if (mov == P_Z) {
//                         dir = M_X;
//                     } else {
//                         dir = P_X;
//                     }
//                 } else if (dir == M_Z) {
//                     if (mov == P_Z) {
//                         dir = P_X;
//                     } else {
//                         dir = M_X;
//                     }
//                 } else if (dir == P_Y) {
//                     if (mov == P_Y) {
//                         dir = M_X;
//                     } else {
//                         dir = P_X;
//                     }
//                 } else if (dir == M_Y) {
//                     if (mov == P_Y) {
//                         dir = P_X;
//                     } else {
//                         dir = M_X;
//                     }
//                 }