#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void stevke(bool* t, int x) {
    while (x != 0)
    {
       int temp = x % 10;
       t[temp] = true;
       x /= 10;
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    bool* nums = calloc(10, sizeof(bool));

    stevke(nums, a);
    stevke(nums, b);

    int howmany = 0;
    for(int i = 0; i < 10; i++) {
        if(nums[i]) howmany++;
    }

    free(nums);
    printf("%d\n", howmany);
    return 0;
}