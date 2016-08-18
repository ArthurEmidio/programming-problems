#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <set>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    scanf("%d", &n);
    getchar();
    
    vector<string> w;
    vector<ll> costs;
    vector<int> und;
    
    for (int i = 0; i < n; i++) {
        ll c;
        cin >> c;
        costs.push_back(c);
    }
    
    string prevW;
    cin >> prevW;
    w.push_back(prevW);
    
    ll totCost = 0;
    
    for (int i = 1; i < n; i++) {
        string word;
        cin >> word;
        w.push_back(word);
        
        if (!lexicographical_compare(prevW.begin(), prevW.end(), word.begin(), word.end())) {
            und.push_back(i);
        }
        
        prevW = word;
    }
    
    for (int i : und) {
        string w1 = w[i - 1];
        string w2 = w[i];
        
        string w1_c = w1;
        
        if (w1.size() < w2.size()) {
            totCost = -1;
            break;
        }
        
        bool ok1 = false;
        reverse(w1.begin(), w1.end());
                
        if (lexicographical_compare(w1.begin(), w1.end(), w2.begin(), w2.end())) {
            if (i - 2 >= 0) {
                string w0 = w[i - 2];
                if (lexicographical_compare(w0.begin(), w0.end(), w1.begin(), w1.end())) {
                    ok1 = true;
                }
            } else {
                ok1 = true;
            }
        }
        
        bool ok2 = false;
        reverse(w2.begin(), w2.end());
        if (lexicographical_compare(w1_c.begin(), w1_c.end(), w2.begin(), w2.end())) {
            if (i + 1 < w.size()) {
                string w3 = w[i + 1];
                if (lexicographical_compare(w2.begin(), w2.end(), w3.begin(), w3.end())) {
                    ok2 = true;
                }
            } else {
                ok2 = true;
            }
        }

        if (ok1 && ok2) {
            if (costs[i - 1] <= costs[i]) {
                totCost += costs[i - 1];
                w[i - 1] = w1;
            } else {
                totCost += costs[i];
                w[i] = w2;
            }
        } else if (ok1) {
            totCost += costs[i - 1];
            w[i - 1] = w1;
        } else if (ok2) {
            totCost += costs[i];
            w[i] = w2;
        } else {
            totCost = -1;
            break;
        }
    }
    
    cout << totCost << endl;

    return 0;
}
