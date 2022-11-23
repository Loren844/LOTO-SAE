#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "case.h"
#include "tirages.h"

int main()
{
    srand(time(NULL));
    system("color F0");

    Case carton1[3][9]={{0}};
    Case carton2[3][9]={{0}};
    Case carton3[3][9]={{0}};

    creeCarton(carton1);
    creeCarton(carton2);
    creeCarton(carton3);

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

    return 0;
}
