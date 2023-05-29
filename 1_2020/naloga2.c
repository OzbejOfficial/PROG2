#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    int value;
    Vozlisce* next;
};

int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

Vozlisce* prepisi(int* t) {
    if(t[0] == 0) return NULL;
    
    Vozlisce* start = malloc(sizeof(Vozlisce));
    Vozlisce* voz = start;
    int cur = t[0];
    int ind = 0;

    while (cur != 0)
    {
        Vozlisce* voz_n = malloc(sizeof(Vozlisce));
        voz->value = cur;
        voz->next = voz_n;
        if(t[ind+1] == 0) voz->next = NULL;

        voz = voz_n;

        ind++;
        cur = t[ind];
    }
    
    return start;
}

int main() {

    Vozlisce* voz = prepisi(t);

    while (voz != NULL)
    {
        printf("%d -> ", voz->value);
        voz = voz->next;
    }
    printf("\n");
    

    return 0;
}