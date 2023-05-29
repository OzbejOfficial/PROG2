#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef FILE* FIRE;

void obrni(FIRE I, FIRE O) {
    char* buffer = malloc(1024 * sizeof(char));
    if(fgets(buffer, sizeof(buffer), I) != NULL) {
        obrni(I, O);
    } else {
        return;
    }
    fputs(buffer, O);
    free(buffer);

    return;
}

int main(int argc, char* argv[]) {
    FIRE input = fopen(argv[1], "r");
    FIRE output = fopen(argv[2], "w+");

    obrni(input, output);

    fclose(input);
    fclose(output);
    return 0;
}