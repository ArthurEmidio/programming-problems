#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define ll long long

int main()
{
    int t = 0;
    
    while (1) {
        int n;
        cin >> n;
        
        if (cin.eof()) break;
        
        if (t > 0) cout << endl;
        
        map<string, int> people;
        vector<string> peopleVector;
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            people[name] = 0;
            peopleVector.push_back(name);
        }
        
        for (int i = 0; i < n; i++) {
            string from;
            cin >> from;
            
            int value;
            cin >> value;
            
            int receivers;
            cin >> receivers;
            
            if (receivers > 0) {
                int costPerPerson = value / receivers;                
                for (int j = 0; j < receivers; j++) {
                    string receiver;
                    cin >> receiver;
                    people[receiver] += costPerPerson;
                }
                people[from] -= receivers * costPerPerson;
            }
        }
        
        for (string name : peopleVector) {
            cout << name << " " << people[name] << endl;
        }
        
        t++;
    }
    
    return 0;
}
