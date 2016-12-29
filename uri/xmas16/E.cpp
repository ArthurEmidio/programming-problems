#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    map<string, set<string>> people;
    for (int i = 0; i < n; i++) {
        string name, item1, item2, item3;
        cin >> name >> item1 >> item2 >> item3;
        people[name].insert(item1);
        people[name].insert(item2);
        people[name].insert(item3);
    }
    
    string name, item;
    while (cin >> name >> item) {
        printf("%s\n", people[name].count(item) ? "Uhul! Seu amigo secreto vai adorar o/" : "Tente Novamente!");
    }
    
    return 0;
}