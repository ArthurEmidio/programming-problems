#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> seq;
map<int, vector<int>> swaps;

inline void findBest(const int &i, vector<int> &maxPermutation)
{
    // uint8_t *visited = (uint8_t*) calloc(seq.size(), sizeof(uint8_t));
    vector<int> visited(seq.size());
    int currMaxIndex = i;
   
    queue<int> toBeVisited;
    toBeVisited.push(i);
       
    while (!toBeVisited.empty()) {
        int currIdx = toBeVisited.front();
        toBeVisited.pop();
        
        if (seq[currMaxIndex] < seq[currIdx] && maxPermutation[currIdx] == -1) {
            currMaxIndex = currIdx;
            // if (i > 0 && seq[currMaxIndex] == maxPermutation[i - 1] - 1) {
            //     break;
            // }
        }
        
        visited[currIdx] = 1;
        
        // if (seq[currIdx] < seq[currMaxIndex]) {
        //     continue;
        // }
        
        for (const int &idx : swaps[currIdx]) {
            if (!visited[idx]) {
                toBeVisited.push(idx);
            }
        }
    }
          
    maxPermutation[i] = seq[currMaxIndex];
    
    seq[currMaxIndex] = seq[i];
    seq[i] = maxPermutation[i];
    
    // free(visited);
}

int main()
{
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        seq.push_back(curr);
    }
    
    for (int i = 0; i < m; i++) {
        int p1, p2;
        scanf("%d %d", &p1, &p2);
        
        if (p1 != p2) {
            swaps[p1 - 1].push_back(p2 - 1);
            swaps[p2 - 1].push_back(p1 - 1);
        }
    }
    
    vector<int> maxPermutation(n, -1);
    for (int i = 0; i < n; i++) {        
        if (maxPermutation[i] == -1) {
            findBest(i, maxPermutation);
        }
        cout << maxPermutation[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
