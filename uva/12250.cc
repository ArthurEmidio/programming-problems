#include <iostream>
#include <limits>
#include <cmath>
#include <map>

using namespace std;

#define ll long long

int main()
{
    map<string, string> words = {{"HELLO", "ENGLISH"},
                                 {"HOLA", "SPANISH"},
                                 {"HALLO", "GERMAN"},
                                 {"BONJOUR", "FRENCH"},
                                 {"CIAO", "ITALIAN"},
                                 {"ZDRAVSTVUJTE", "RUSSIAN"}};
                                 
    int i = 1;
    while (1) {
        string word;
        cin >> word;
        
        if (word == "#") break;
        
        cout << "Case " << i << ": ";
        if (words.count(word) == 0) {
            cout << "UNKNOWN";
        } else {
            cout << words[word];
        }
        cout << endl;
        
        i++;
    }
    
    return 0;
}