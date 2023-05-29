#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printTree(int* nums, int n, int cur) {
    if(cur > n) return;
    printf("%d", nums[cur-1]);
    printTree(nums, n, cur * 2);
    printTree(nums, n, cur * 2 + 1);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    int many = ((int) exp2(n)) - 1;
    int* nums = malloc(many * sizeof(int));

    for(int i = 0; i < many; i++) {
        scanf("%d", &nums[i]);
    }

    printTree(nums, many, 1);
    printf("\n");

    free(nums);
    return 0;
}