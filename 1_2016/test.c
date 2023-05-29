#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[] = {20, 18, 16, 16, 14, 11, 10, 9, 7, 4, 1, 1, 1, 1, 2};
    //int numbers[] = {5, 15, 23, 10, 17, 20, 2, 2, 1};
    //int numbers[] = {5, 5, 5, 5, 5, 15, 23, 10, 17, 20, 2, 2, 1};
    int n = 15;
    // int n = 8;
    // int n = 13;

    int maxLen = 0;
    int curLen = 0;

    for (int i = 0; i < n; i++) {
        int curNum = numbers[i];
        curLen += 1;
        for (int j = 0; j < n; j++) {
            if (curNum % numbers[j] == 0) {
                curNum = numbers[j];
                curLen += 1;
            }
        }
        if (curLen > maxLen) {
            maxLen = curLen;
        }    
        curLen = 0;
    }

    printf("%d\n", maxLen);
    return 0;
}