#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> Position;

map<int, Position> keys;
map<Position, int> keyMap;

void initKeys()
{
    keys[0] = Position(3, 1);
    keyMap[Position(3, 1)] = 0;
    
    int n = 1;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            keys[n] = Position(i, j);
            keyMap[Position(i, j)] = n;
            n++;
        }
    }
}

bool exists(int digitStart, vector<Position> sequence)
{
    if (sequence.empty()) {
        return true;
    }
    
    Position keyPos = keys[digitStart];
    Position newPos(keyPos.first - sequence[0].first, keyPos.second - sequence[0].second);
    
    if (keyMap.count(newPos) == 0) {
        return false;
    }
    
    int nextDigit = keyMap[newPos];
    sequence.erase(sequence.begin());
    
    return exists(nextDigit, sequence);
}

int main() {
    initKeys();
    
    int howManyDigits;
    scanf("%d", &howManyDigits);
    getchar();
    
    vector<int> phone;
    for (int i = 0; i < howManyDigits; i++) {
        char digit;
        scanf("%c", &digit);
        phone.push_back(digit - 48);
    }

    vector<Position> sequence;
    for (int i = 0; i < howManyDigits - 1; i++) {
        Position posDigit1 = keys[phone[i]];
        Position posDigit2 = keys[phone[i + 1]];
        
        int diffV = posDigit1.first - posDigit2.first;
        int diffH = posDigit1.second - posDigit2.second;
                
        sequence.push_back(Position(diffV, diffH));
    }

    bool valid = true;
    for (int i = 0; i < 10; i++) {
        if (i == phone[0]) {
            continue;
        }

        if (exists(i, sequence)) {
            valid = false;
            break;
        }
    }
    
    printf("%s\n", valid ? "YES" : "NO");
}
