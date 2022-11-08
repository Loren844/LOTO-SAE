#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tirages.h"

void creerCarton()
{
    int nbValCol[9]={1,1,1,1,1,1,1,1,1};
    int carton[3][9]={{0}};
    int listeVal[15];

    tirageCol(nbValCol);
    tirageLig(nbValCol,carton[3][9]);
    affichCarton(carton);
    tirageNb(nbValCol[],listeVal[]);
    triBulle(listeVal,15);

}
