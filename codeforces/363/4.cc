#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    
    int changes = 0;
    vector<int> roots;
    vector<int> parents;
    vector<vector<int>> nodes(n);
    
    map<int, int> visitStatus;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        
        visitStatus[i] = 0;
        parents.push_back(a);
        
        if (a == i) {
            roots.push_back(a);
        } else {
            nodes[a].push_back(i);
        }        
    }
    
    queue<int> toVisit;
    int mainRoot = -1;
    if (!roots.empty()) {
        mainRoot = roots[0];
        
        for (int i = 1; i < roots.size(); i++) {
            nodes[mainRoot].push_back(roots[i]);
            parents[roots[i]] = mainRoot;
            changes++;
        }
        
        toVisit.push(mainRoot);
        visitStatus.erase(mainRoot);
    
        while (!toVisit.empty()) {
            int nodeIndex = toVisit.front();
            toVisit.pop();
        
            vector<int> &children = nodes[nodeIndex];
            for (int i = 0; i < children.size(); i++) {
                int child = children[i];
                auto it = visitStatus.find(child);
                if (it != visitStatus.end()) {
                    visitStatus.erase(it);
                    toVisit.push(child);
                } else {
                    changes++;
                    nodes[nodeIndex].erase(children.begin() + i);
                    i--;
                    
                    nodes[mainRoot].push_back(child);
                    parents[child] = mainRoot;
                }   
            }
        }
    }
    
    int rem = visitStatus.size();    
    int currRound = 0;
    
    while (rem > 0) {
        int newRoot = visitStatus.begin()->first;
        toVisit.push(newRoot);
        visitStatus.erase(visitStatus.begin());
        
        currRound++;
        
        while (!toVisit.empty()) {
            int nodeIndex = toVisit.front();
            toVisit.pop();
                
            vector<int> &children = nodes[nodeIndex];
            for (int i = 0; i < children.size(); i++) {
                int child = children[i];
                rem--;                
                
                if (visitStatus[child] == 0) {
                    visitStatus[child] = currRound;
                    toVisit.push(child);
                } else if (visitStatus[child] == currRound) {                    
                    changes++;
                    nodes[nodeIndex].erase(children.begin() + i);
                    i--;
                    
                    if (mainRoot == -1) {
                        mainRoot = child;
                        parents[child] = child;
                    } else {
                        nodes[mainRoot].push_back(child);
                        parents[child] = mainRoot;
                    }
                }   
            }
        }
    }
    
    cout << changes << endl;
    for (int i = 0; i < n; i++) {
        cout << (parents[i] + 1) << " ";
    }
    cout << endl;
    
    return 0;
}
