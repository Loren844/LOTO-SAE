#include "case.h"
#include "tirages.h"

void initCartons(Case carton1[][9], Case carton2[][9], Case carton3[][9])
{
    creerCartons(carton1,carton2,carton3);

    modifCartons(carton1, carton2, carton3);
}

void remplirListe(int liste[])
{
    for (int i = 0;i < 89; i++)
    {
        liste[i] = i+1;
    }
}
