#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef FILE* FIRE;

void odstraniDuplikate(FIRE I, FIRE O) {
    char bc = 0;
    char c;
    while((c = fgetc(I)) != EOF)
    {
        if(bc != c) {
            fputc(c, O);
            bc = c;
        }
    }
}

int main(int argc, char* argv[]) {
    
    FIRE Input = fopen(argv[1], "r");
    FIRE Output = fopen(argv[2], "w+");

    odstraniDuplikate(Input, Output);

    fclose(Input);
    fclose(Output);    
    return 0;
}