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

    affichCarton(carton1);

    /*
    printf("Joueur 1 :\n");
    affichCarton(carton1);
    printf("\nJoueur 2 :\n");
    affichCarton(carton2);
    printf("\nJoueur 3 :\n");
    affichCarton(carton3);

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
