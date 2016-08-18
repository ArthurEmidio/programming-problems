#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

#define ll long long

int main()
{
    for (;;) {
        int k, m;
        cin >> k;
        if (k == 0) break;
        cin >> m;
    
        set<string> courses;
        for (int i = 0; i < k; i++) {
            string course;
            cin >> course;
            courses.insert(course);
        }
    
        bool graduate = true;
        for (int i = 0; i < m; i++) {
            int c, r;
            cin >> c >> r;
        
            for (int i = 0; i < c; i++) {
                string course;
                cin >> course;
            
                if (courses.count(course) > 0) {
                    r--;
                }
            }
        
            if (r > 0) {
                graduate = false;
            }
        }
        
        cout << (graduate ? "yes" : "no") << endl;
    }
    
    return 0;
}