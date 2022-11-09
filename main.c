#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tirages.h"

int main()
{
    srand(time(NULL));
    system("color F0");

    int carton1[3][9]={{0}};
    int carton2[3][9]={{0}};
    int carton3[3][9]={{0}};

    creeCarton(carton1);
    creeCarton(carton2);
    creeCarton(carton3);

    printf("Joueur 1 :\n");
    affichCarton(carton1);
    printf("\nJoueur 2 :\n");
    affichCarton(carton2);
    printf("\nJoueur 3 :\n");
    affichCarton(carton3);



    int listeTirage[90]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89};
    int tailleListeTirage=90,indTire,valTiree;
    while(tailleListeTirage>0)
    {
        indTire=rand()%tailleListeTirage;
        valTiree=listeTirage[indTire];
        suppElemPos(listeTirage,indTire,tailleListeTirage);
        tailleListeTirage--;
        printf("\n%d",valTiree);
    }

    return 0;
}
