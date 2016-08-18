#include <iostream>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    
    vector<string> people;
    vector<string> song = {"Happy", "birthday", "to", "you",
                           "Happy", "birthday", "to", "you",
                           "Happy", "birthday", "to", "Rujia",
                           "Happy", "birthday", "to", "you"};
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        people.push_back(s);
    }
    
    int i = 0;
    while (i < n) {  
        int j = 0;
        while (j < song.size()) {
            cout << people[i % n] << ": " << song[j % song.size()] << endl;
            i++;
            j++;
        }
    }
    
    return 0;
}
