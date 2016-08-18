#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

class Node
{
public:
    list<Node*> neighbors;
    int index;
    
    Node *parent;
    int distance;
    bool visited;
    
    Node(int i) : index(i), parent(nullptr), distance(INFINITY), visited(false) { }
    
};

void dijkstra(Node *start, const vector<Node*> &nodes)
{
    start->distance = 0;
    priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>> pq([](Node *n1, Node *n2) -> bool {
        return n1->distance > n2->distance;
    });
    
    pq.push(start);
        
    while (!pq.empty()) {
        Node *current = pq.top();
        pq.pop();
        if (current->visited) continue;
        
        current->visited = true;
        for (Node *neighbor : current->neighbors) {
            int distance = current->distance + 1;
            neighbor->distance = min(distance, neighbor->distance);
            if (!neighbor->visited) pq.push(neighbor);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<Node*> nodes;
    vector<int> shortcuts;
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        shortcuts.push_back(curr - 1);
        
        Node *node = new Node(i);
        nodes.push_back(node);   
    }
    
    for (int i = 0; i < n; i++) {
        int shortcut = shortcuts[i];
        Node *node = nodes[i];
        
        if (shortcut > i) {
            node->neighbors.push_back(nodes[shortcut]);
        }
        
        if (i + 1 < shortcuts.size()) {
            node->neighbors.push_back(nodes[i + 1]);
            nodes[i+1]->neighbors.push_back(node);
        }
    }
    
    dijkstra(nodes[0], nodes);
    
    for (Node *node : nodes) {
        cout << node->distance << " ";
    }
    cout << endl;
    
    return 0;
}
