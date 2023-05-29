#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int** t = malloc(201 * sizeof(int*));
    for(int i = 0; i < 201; i++) {
        t[i] = calloc(201, sizeof(int));
    }

    int* cover = calloc(n+1, sizeof(int));

    int y, x, len;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &y, &x, &len);

        for(int j = (y+100); j < (y+100+len); j++) {
            for(int k = (x+100); k < (x+100+len); k++) {
                int x = t[j][k]+1;
                t[j][k] = x;
                cover[x-1] -= 1;
                cover[x] += 1;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        printf("%d\n", cover[i]);
    }

    free(cover);
    for(int i = 0; i < 201; i++) {
        free(t[i]);
    }
    free(t);

    return 0;
}