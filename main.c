#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creerCartons.h"

int main()
{
    menuDem();

    srand(time(NULL));
    for(int i=0;i<3;i++)
    {
       creerCarton();
    }

    tirageLoto(); //affichage des cartons, du menu (tirer,pause,nouvelle partie...)

    comptePoints();

    return 0;
}
