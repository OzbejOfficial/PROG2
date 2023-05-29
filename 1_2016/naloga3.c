#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max = 0;

void rekurzija(int cur, int dist, int n, int* nums, bool* memo) {
    if(dist > max) max = dist;
    for(int i = 0; i < n; i++) {
        if(cur % nums[i] == 0 && memo[i] == false) {
            memo[i] = true;
            rekurzija(nums[i], dist+1, n, nums, memo);
            memo[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* nums = malloc(n * sizeof(int));
    bool* memo = calloc(n, sizeof(bool));

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for(int i = 0; i < n; i++) {
        memo[i] = true;
        rekurzija(nums[i], 1, n, nums, memo);
        memo[i] = false;
    }

    printf("%d\n", max);
    return 0;
}