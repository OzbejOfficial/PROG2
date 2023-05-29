#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char* i;

bool izracunaj() {
    if(i[0] == 'T') return true;
    else if(i[0] == 'F') return false;
    else if(i[0] == '&') {
        i++;
        bool a = izracunaj(i);
        i++;
        bool b = izracunaj(i);
        //printf("%d & %d\n", a, b);
        return (a && b);
    } else if(i[0] == '|') {
        i++;
        bool a = izracunaj(i);
        i++;
        bool b = izracunaj(i);
        //printf("%d | %d\n", a, b);
        return (a || b);
    } else if(i[0] == '!') {
        i++;
        bool a = izracunaj(i);
        //printf("!%d\n", a);
        return (!a);
    } else {
        printf("Neveljaven izraz!\n");
    }

    return false;
}

int main() {
    char* izraz = malloc(1000 * sizeof(char));
    scanf("%s", izraz);

    i = izraz;

    bool vrednost_izraza = izracunaj();
    if(vrednost_izraza) printf("T\n");
    else printf("F\n");

    return 0;
}