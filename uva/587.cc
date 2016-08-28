#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point
{
    double x;
    double y;
    
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) { }
    
    inline double distTo(const Point &p) const
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

int main()
{
    for (int t = 1; ; t++) {
        string line;
        getline(cin, line);
        if (line == "END") break;
        
        istringstream iss(line);
        Point p;
        for (;;) {
            int q;
            iss >> q;
        
            char firstChar, secondChar;
            iss >> firstChar >> secondChar;
            string coord;
            coord += firstChar;            
            if (secondChar != ',' && secondChar != '.') coord += secondChar;
            
            const double diagMove = q * sqrt(2) / 2.0;
            if (coord == "N") {
                p.y += q;
            } else if (coord == "NW") {
                p.x -= diagMove;
                p.y += diagMove;
            } else if (coord == "W") {
                p.x -= q;
            } else if (coord == "SW") {
                p.x -= diagMove;
                p.y -= diagMove;
            } else if (coord == "S") {
                p.y -= q;
            } else if (coord == "SE") {
                p.x += diagMove;
                p.y -= diagMove;
            } else if (coord == "E") {
                p.x += q;
            } else {
                p.x += diagMove;
                p.y += diagMove;
            }
                                    
            if (secondChar != ',' && secondChar != '.') iss >> secondChar;
            if (secondChar == '.') break;
        }
        
        printf("Map #%d\n", t);
        printf("The treasure is located at (%.3f,%.3f).\n", p.x, p.y);
        printf("The distance to the treasure is %.3f.\n\n", p.distTo(Point(0,0)));
    }
    
    return 0;
}
