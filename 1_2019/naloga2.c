#include <stdio.h>
#include <stdlib.h>

typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};


Vozlisce* rekurzija(Vozlisce* zdajsnje, int prvi) {
    Vozlisce* temp = zdajsnje->naslednje;
    Vozlisce* returnable = NULL;

    if(temp == NULL) {
        return zdajsnje;
    } else {
        returnable = rekurzija(temp, 1);
    }
    temp->naslednje = zdajsnje;

    if(prvi == 0) zdajsnje->naslednje = NULL;
    return returnable;
}

Vozlisce *obrni(Vozlisce *zacetno)
{
    return rekurzija(zacetno, 0);
}

int main()
{
    Vozlisce *prvo = malloc(sizeof(Vozlisce));
    Vozlisce *drugo = malloc(sizeof(Vozlisce));
    Vozlisce *tretje = malloc(sizeof(Vozlisce));
    Vozlisce *cetrto = malloc(sizeof(Vozlisce));
    Vozlisce *peto = malloc(sizeof(Vozlisce));
    
    prvo->naslednje = drugo;
    drugo->naslednje = tretje;
    tretje->naslednje = cetrto;
    cetrto->naslednje = peto;
    peto->naslednje = NULL;

    prvo->podatek = 1;
    drugo->podatek = 2;
    tretje->podatek = 3;
    cetrto->podatek = 4;
    peto->podatek = 5;

    Vozlisce *obravnavano = malloc(sizeof(Vozlisce));
    obravnavano = prvo;
    printf("Pravi vrstni red: \n");
    while (obravnavano != NULL)
    {
        printf("%d ", obravnavano->podatek);
        obravnavano = obravnavano->naslednje;
    }

    printf("\nZdaj pa obrnemo:\n");

    obravnavano = obrni(prvo);
    while (obravnavano != NULL)
    {
        printf("%d ", obravnavano->podatek);
        obravnavano = obravnavano->naslednje;
    }

    printf("\n");
    free(obravnavano);
    free(prvo);
    free(drugo);
    free(tretje);
    free(cetrto);
    free(peto);

    return 0;
}