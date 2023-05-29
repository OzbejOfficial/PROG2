#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _polje {
    int name;
    int x;
    int y;
} polje;

int main() {
    int y, x, g;
    scanf("%d %d %d", &y, &x, &g);

    polje** polja = malloc(y*x*sizeof(polje*));
    for(int i = 0; i < x*y; i++) {
        int cur;
        scanf("%d", &cur);
        int c_x = i % x;
        int c_y = i / x;

        polje* temp = malloc(sizeof(polje));
        temp->name = cur;
        temp->x = c_x;
        temp->y = c_y;

        polja[cur] = temp;
    }

    int cur_polje = 0;
    while (true)
    {
        g -= abs(polja[cur_polje]->x - polja[cur_polje+1]->x);
        g -= abs(polja[cur_polje]->y - polja[cur_polje+1]->y);
        if(g < 0) break;
        cur_polje++;
    }
    
    printf("%d\n", cur_polje);
    return 0;
}