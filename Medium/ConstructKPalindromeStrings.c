#include <stdbool.h>

int getSetBits(int num) {
    int count = 0;
    while(num) {
        num = num & (num - 1);
        ++count;
    }
    return count;
}

bool canConstruct(char* s, int k) {
    int count = 0, sLen = strlen(s);

    if(k == sLen) return true;
    else if(sLen < k) return false;
    
    for(int i = 0; s[i]; i++) {
        count ^= 1 << (s[i] - 'a');
    }

    int setBits = getSetBits(count);
    return setBits <= k;
}