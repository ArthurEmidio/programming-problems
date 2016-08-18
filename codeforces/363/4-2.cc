#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> parents; // stores the input
    vector<int> visit; // stores the round where each node was visited
    set<int> toVisit; // stores all nodes "n" which visit[n] == 0
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        
        parents.push_back(a);
        visit.push_back(0);
        toVisit.insert(i);
    }

    vector<int> roots; // stores all root nodes    
    int round = 0;
    int firstRoot = -1;
    
    while (!toVisit.empty()) {
        round++;
        int currNode = *(toVisit.begin());
        
        while (visit[currNode] == 0) { // while not root and not visited before         
            toVisit.erase(currNode);
            visit[currNode] = round;
            currNode = parents[currNode];                        
        }                
                
        if (firstRoot == -1 && parents[currNode] == currNode) {
            firstRoot = currNode;
        } else if (visit[currNode] == round) { // reached a root node or a node that was visited in the same round (cycle!)
            roots.push_back(currNode);
        }
    }
    
    int changes = 0;    
    if (firstRoot == -1) firstRoot = roots[0];
    for (int i = 0; i < roots.size(); i++) {        
        changes++;
        parents[roots[i]] = firstRoot;
    }

    cout << changes << endl;
    for (int i = 0; i < parents.size(); i++) {
        cout << parents[i] + 1 << " ";
    }
    cout << endl;
    
    return 0;
}
