#include <stdio.h>
#include <stdlib.h>

int counter = 0;

void simuliraj(int koraki, int visina) {
    if(visina<0) return;
    if(visina-koraki>0) return;
    if(koraki == 0) {
        if(visina == 0) {
            counter++;
            return;
        } else return;
    }

    simuliraj(koraki-1, visina+1);
    simuliraj(koraki-1, visina-1);

    return;
}

int main() {
    int n;
    scanf("%d", &n);

    simuliraj(n, 0);
    printf("%d\n", counter);

    return 0;
}