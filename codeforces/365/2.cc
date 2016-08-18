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
    int n, k;
    cin >> n >> k;
    
    vector<int> cities;
    ll totBeauty = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cities.push_back(c);
        totBeauty += c;
    }
    
    vector<int> capitals;
    for (int i = 0; i < k; i++) {
        int id;
        cin >> id;
        capitals.push_back(id - 1);
    }

    ll price = 0;

    for (int i = 0; i < capitals.size(); i++) {
        int j = capitals[i];
        
        totBeauty -= cities[j];
        price += cities[j] * totBeauty;
        cities[j] = -1;
    }

    int howManyCities = cities.size() - 1;
    for (int i = 0; i < howManyCities; i++) {
        if (cities[i] == -1 || cities[i + 1] == -1) continue;
        if (cities[i] != -1 && cities[i + 1] != -1) {
            price += cities[i] * cities[i + 1];
        }
    }
    if (cities[howManyCities] != -1 && cities[0] != -1) price += cities[howManyCities] * cities[0];
    
    cout << price << endl;

    return 0;
}
