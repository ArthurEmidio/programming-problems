#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define ll long long

void countChildren(vector<pair<vector<int>, int>> &cities)
{
    stack<int> st;
    vector<bool> visited(cities.size(), 0);
    
    st.push(0);
    visited[0] = true;
    
    while (!st.empty()) {
        int id = st.top();
        pair<vector<int>, int> &parent = cities[id];
        visited[id] = true;
        
        if (parent.first.empty() || visited[parent.first[0]]) {
            st.pop();
            
            parent.second = parent.first.size();
            for (int child : parent.first) {
                parent.second += cities[child].second;
            }            
        } else {
            for (int child : parent.first) {
                st.push(child);
            }
        }
    }    
}

int main()
{
    int n;
    cin >> n;
    
    vector<pair<vector<int>, int>> cities(n, make_pair(vector<int>(), 0));
    
    for (int i = 1; i < n; i++) {
        int curr;
        cin >> curr;
        curr--;
        
        pair<vector<int>, int> &parent = cities[curr];
        parent.first.push_back(i);
    }       
    
    countChildren(cities);
    
    vector<double> times(n);
    times[0] = 1.0;
        
    queue<int> toVisit;
    toVisit.push(0);
    
    while (!toVisit.empty()) {
        int cityId = toVisit.front();
        toVisit.pop();
        
        double cityTime = times[cityId];
        
        pair<vector<int>, int> &cityInfo = cities[cityId];
        vector<int> &children = cityInfo.first;
        
        for (int child : children) {
            pair<vector<int>, int> &childCity = cities[child];
            
            int comesAfterParent = cityInfo.second;
            int comesAfterChild = childCity.second;
            int comesAfterOtherChildren = comesAfterParent - comesAfterChild - 1;
            
            if (comesAfterOtherChildren > 0) {
                double avgDist = (cityTime + 1) + (comesAfterOtherChildren / 2.0);
                times[child] = avgDist;
            } else {
                times[child] = cityTime + 1.0;
            }
            
            toVisit.push(child);
        }
    }
    
    for (double startTime : times) {
        printf("%.1f ", startTime);
    }
    cout << endl;
    
    return 0;
}
