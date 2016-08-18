#include <iostream>

using namespace std;

#define DEG 9

int rotations(int pos, int a, int b, int c)
{    
    int rot = 360 * 2;
    
    if (pos < a) {
        rot += (pos + 1) * DEG;
        pos = 39;
    }
    rot += (pos - a) * DEG;
    pos = a;
    
    rot += 360;
    
    if (pos > b) {
        rot += (39 - pos + 1) * DEG;
        pos = 0;
    }
    rot += (b - pos) * DEG;
    pos = b;
    
    if (pos < c) {
        rot += (pos + 1) * DEG;
        pos = 39;
    }
    rot += (pos - c) * DEG;
    
    return rot;
}

int main()
{
    int pos, a, b, c;
    while (1) {  
        scanf("%d %d %d %d", &pos, &a, &b, &c);
        if (pos == 0 && a == 0 && b == 0 && c == 0) {
            break;
        }
              
        cout << rotations(pos, a, b, c) << endl;
    }
}
