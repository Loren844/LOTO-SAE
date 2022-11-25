#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "case.h"

//a modifier
void affichCarton(Case tab[][9])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<9;j++)
        {
            int val = afficheValeur(tab);
            printf("%d ",val);
        }
        printf("\n");
    }
}

//fonctionne
void creerCarton(Case carton[][9])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            modifValeur(&carton[i][j], 0);
            modifestTiree(&carton[i][j], 0);
        }
    }
}

/*
void modifCarton(Case carton[][9])
{
    int nbValCol[9]={1,1,1,1,1,1,1,1,1};

    int listeVal[15]={0};

    tirageCol(nbValCol);

    int nbValCol2[9];
    copieTab(nbValCol,nbValCol2,9);

    tirageLig(nbValCol,carton);

    tirageNb(nbValCol2,listeVal);
    triBulle(listeVal,15);

    remplace1(carton,listeVal);
}
*/
