#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);    
    
    int bw = 0;
    vector<int> books_t1, books_t2;
    for (int i = 0; i < n; i++) {
        int t, w;
        scanf("%d %d", &t, &w);
        if (t == 1) books_t1.push_back(w);
        else books_t2.push_back(w);
        bw += w;
    }
    
    sort(books_t1.begin(), books_t1.end(), std::greater<int>());
    sort(books_t2.begin(), books_t2.end(), std::greater<int>());
        
    int i = 0, j = 0, bt = 0;
    while (bt < bw && i < books_t1.size() && j < books_t2.size()) {        
        if ((books_t1[i] >= books_t2[j] && bt+2 < bw-books_t2[i]) || bt+1 >= bw-books_t1[i]) {
            bt++;
            bw -= books_t1[i++];
        } else if (i+1 < books_t1.size() && books_t2[j] < books_t1[i] + books_t1[i+1]) {
            bt += 2;
            bw -= books_t1[i] + books_t1[i+1];
            i += 2;
        } else {
            bt += 2;
            bw -= books_t2[j++];
        }
    }
        
    while (bt < bw && i < books_t1.size()) bt++, bw -= books_t1[i++];    
    while (bt < bw && j < books_t2.size()) bt+=2, bw -= books_t2[j++];
    
    printf("%d\n", bt);
    
    return 0;
}
