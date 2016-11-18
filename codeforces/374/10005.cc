#include <bits/stdc++.h>

using namespace std;

#define oo 9223372036854775807
#define EPS 1e-6
#define PI 3.141592653589793

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

inline bool equals(double x, double y)
{
    return fabs(x - y) < EPS;
}

class Point
{
public:
    double x, y;
    
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    
    double distance(const Point &p) const
    {
        return hypot(x - p.x, y - p.y);
    }
      
};

class Circle
{
public:
    Point C;
    double r;
    
    Circle(const Point &_C = Point(), double _r = 0) : C(_C), r(_r) {} 
    
};

int main()
{
    for (;;) {
        int n;
        cin >> n;
        if (!n) break;
        
        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points.x >> points.y;
        }
        
        double r;
        cin >> r;
        
        bool possible = true;
        for (int i = 0; i < n && possible; i++) {
            for (int j = i + 1; j < n && possible; j++) {
                double dist = points[i].distance(points[j]);
                if (dist > 2*r) {
                    possible = false;
                }
            }
        }
        
        if (possible) {
            printf("The polygon can be packed in the circle.\n");
        } else {
            printf("There is no way of packing that polygon.\n");
        }
    }
    
    return 0;
}