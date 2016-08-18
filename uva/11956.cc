#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    
    for (int i = 0; i < t; i++) {
        vector<uint8_t> mem(100, 0);
        
        char c;
        scanf("%c", &c);
        uint8_t pointer = 0;
        
        while (c != '\n') {
            if (c == '>') {
                pointer = (pointer == 99) ? 0 : (pointer + 1);
            } else if (c == '<') {
                pointer = (pointer == 0) ? 99 : (pointer - 1);
            } else if (c == '+') {
                mem[pointer]++;
            } else if (c == '-') {
                mem[pointer]--;
                
            }
                        
            scanf("%c", &c);
        }
        
        printf("Case %d:", i + 1);
        for (uint8_t n : mem) {
            printf(" %02X", n);
        }
        printf("\n");
        
    }
    
    return 0;
}
