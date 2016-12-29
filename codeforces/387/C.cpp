#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector<int> vi;

struct Task
{
    int id;
    int arrival;
    int servers_req;
    int time;
    vector<int> servers;
};

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, q;
    scanf("%d %d", &n, &q);
    
    set<int> available;
    for (int i = 1; i <= n; i++) available.insert(i);
    
    queue<Task*> tasks;
    int limit;
    for (int i = 0; i < q; i++) {
        Task *t = new Task();
        scanf("%d %d %d", &(t->arrival), &(t->servers_req), &(t->time));
        t->id = i;
        tasks.push(t);
        limit = max(limit, t->arrival + t->time);
    }
    
    auto func = [](Task* t1, Task *t2) {
        return (t1->arrival + t1->time) > (t2->arrival + t2->time); 
    };
    
    priority_queue<Task*, vector<Task*>, decltype(func)> pq(func);
    vector<int> ans(q);
    for (int i = 1; i <= limit; i++) {
        while (!pq.empty() && pq.top()->arrival + pq.top()->time == i) {
            Task *t = pq.top();
            pq.pop();
            for (int server : t->servers) available.insert(server);
            delete t;
        }

        vector<Task*> arrived;
        while (!tasks.empty() && tasks.front()->arrival == i) {
            Task *t = tasks.front(); tasks.pop();
            if (t->servers_req <= available.size()) {
                int sum = 0;
                int quant = t->servers_req;
                while (quant) {
                    int server = *(available.begin());
                    sum += server;
                    t->servers.push_back(server);
                    available.erase(available.begin());
                    quant--;
                }

                pq.push(t);
                ans[t->id] = sum;
            } else {
                ans[t->id] = -1;
            }
        }
    }

    for (int a : ans) printf("%d\n", a);
    
    return 0;
}
