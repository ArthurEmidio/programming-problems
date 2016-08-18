#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    
    map<int, vector<int>> cards;
    
    int maxCard = 0;
    int minCard = 101;
    
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        
        maxCard = max(v, maxCard);
        minCard = min(v, minCard);
        
        cards[v].push_back(i + 1);
    }
    
    int sum = maxCard + minCard;
    
    while (!cards.empty()) {
        pair<int, vector<int>> card = *(cards.begin());
        int firstCardVal = card.first;
        
        vector<int> &firstCard = cards[firstCardVal];
        int firstCardIdx = firstCard.front();
        firstCard.erase(firstCard.begin());
        if (firstCard.empty()) {
            cards.erase(firstCardVal);
        }
        
        vector<int> &otherCard = cards[sum - firstCardVal];
        int secondCardIdx = otherCard.front();
        otherCard.erase(otherCard.begin());
        if (otherCard.empty()) {
            cards.erase(sum - firstCardVal);
        }
        
        cout << firstCardIdx << " " << secondCardIdx << endl;
    }
    
    return 0;
}
