#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
        
    vector<string> words;
    string word;
    for (int i = 0; i < s.size(); i++) {
        word += s[i];
        int wSize = word.size();
        if (wSize >= 3 && word[wSize-1] == 'B' && word[wSize-2] == 'U' && word[wSize-3] == 'W') {
            word.erase(wSize - 3, 3);
            if (!word.empty()) words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) words.push_back(word);
            
    for (int i = 0; i < words.size(); i++) {
        if (i > 0) cout << " ";
        cout << words[i];
    }
    cout << endl;
    
    return 0;
}