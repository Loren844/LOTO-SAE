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

    creerCarton(carton1);
    creerCarton(carton2);
    creerCarton(carton3);

    affichCartons(carton1,carton2,carton3);

    modifCarton(carton1[][9]);
    /*
    int listeTirage[89]={0};
    for (int i = 0;i < 89; i++)
    {
        listeTirage[i] = i+1;
    }

    int tailleListeTirage=89,indTire,valTiree;
    while(tailleListeTirage>0)
    {
        indTire=rand()%tailleListeTirage;
        valTiree=listeTirage[indTire];
        suppElemPos(listeTirage,indTire,tailleListeTirage);
        tailleListeTirage--;
    }
    */
    return 0;
}
