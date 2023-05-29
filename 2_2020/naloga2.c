#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce* izloci(Vozlisce* zac, Vozlisce* v) {
    Vozlisce* start = zac;
    Vozlisce* curr = zac;

    if(start == v) {
        start = start->naslednje;
    }
    else {
        while(curr->naslednje != NULL) {
            if(curr->naslednje == v) {
                curr->naslednje = curr->naslednje->naslednje;
                return start;
            }
            curr = curr->naslednje;
        }
    }

    return start;
}

int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

int main() {
    Vozlisce* zac = malloc(sizeof(Vozlisce));
    Vozlisce* tre = zac;
    tre->podatek = t[0];

    Vozlisce* v;

    for(int i = 1; i <= 10; i++) {
        Vozlisce* temp = malloc(sizeof(Vozlisce));
        tre->naslednje = temp;
        temp->podatek = t[i];
        temp->naslednje = NULL;
        if(i == 7) v = tre;
        tre = temp;
    }

    Vozlisce* read = izloci(zac, v);
    while (read->naslednje != NULL)
    {
        printf("%d -> ", read->podatek);
        read = read->naslednje;
    }
    printf("\n");

    free(zac);
    return 0;
}