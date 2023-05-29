#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print(int n, int* nums, bool* used) {
    printf("{");
    bool first = true;
    for(int i = 0; i < n; i++) {
        if(used[i]) {
            if(first) first = false;
            else printf(", ");
            printf("%d", nums[i]);
        }
    }
    printf("}\n");
}

void rekurzija(int n, int ind, int* nums, bool* used) {
    print(n, nums, used);
    for(int i = ind; i < n; i++) {
        if(!used[i]) {
            used[i] = true;
            rekurzija(n, ind+1, nums, used);
            used[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* nums = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    bool* used = calloc(n, sizeof(bool));
    rekurzija(n, 0, nums, used);

    return 0;
}