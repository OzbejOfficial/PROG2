#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef FILE* FIRE;

char buffer[1024];

int main() {
    char* s_in = malloc(20 * sizeof(char));
    char* s_out = malloc(20 * sizeof(char));
    char c;
    scanf("%s %s %c", s_in, s_out, &c);
    FIRE input, output;
    input = fopen(s_in, "r");
    output = fopen(s_out, "w+");

    int ind_vrstice = 0;
    
    int index = 0;
    while(fgets(buffer, sizeof(buffer), input) != NULL) {
        for(int i = 0; i < (int) strlen(buffer); i++) {
            if(buffer[i] == c) {
                ind_vrstice = index;
                continue;
            }
        }
        index += 1;
    }

    fseek(input, 0, SEEK_SET);
    for(int i = 0; i <= ind_vrstice; i++) fgets(buffer, sizeof(buffer), input);
    fputs(buffer, output);

    free(s_in);
    free(s_out);

    fclose(input);
    fclose(output);
    return 0;
}