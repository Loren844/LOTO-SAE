#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "case.h"
#include "tirages.h"

int main()
{
    srand(time(NULL));

    Case carton1[3][9];
    Case carton2[3][9];
    Case carton3[3][9];

    creerCartons(carton1,carton2,carton3);

    modifCartons(carton1, carton2, carton3);

    affichCartons(carton1,carton2,carton3);


    int listeTirage[89]={0};
    remplirListe(listeTirage);


    int tailleListeTirage=89,indTire,valTiree;
    while(tailleListeTirage>0)
    {
        indTire=rand()%tailleListeTirage;
        valTiree=listeTirage[indTire];
        suppElemPos(listeTirage,indTire,tailleListeTirage);
        tailleListeTirage--;
    }

    return 0;
}
