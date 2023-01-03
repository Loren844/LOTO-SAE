#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menuLoto.h"
#include "case.h"
#include "tirages.h"
#include "bibliotheque.h"
#include "SaveParty.h"

int main()
{
    system("color F0");
    srand(time(NULL));
    int dem = menuDemarrage(); //affichage du menu de démarrage

    //creation de 3 cartons
    Case carton1[3][9];
    Case carton2[3][9];
    Case carton3[3][9];

    //creation/remplissage de la liste de nombres
    int listeTirage[90] = {0};
    int tailleListe = 90;

    //initialisation de variables utiles
    int points[3] = {0, 0, 0};
    int nbTiresJ1[3][1] = {{0},{0},{0}};
    int nbTiresJ2[3][1] = {{0},{0},{0}};
    int nbTiresJ3[3][1] = {{0},{0},{0}};
    int nbPhases = 0; //correspond au nb de phases deja faites (quine, bingo..)

    if (dem == 1)
    {
        initCartons(carton1,carton2,carton3);
        remplirListe(listeTirage);
    }

    else if (dem == 2)
    {
        //importDonnees();
        //recupNbTires(carton1, carton2, carton3, nbTiresJ1, nbTiresJ2,nbTiresJ3);
        //recupPhase(points[], &nbPhase);
    }

    while(nbPhases != 3)
    {
        int nbHasard = tirageNbHasard(listeTirage, &tailleListe);
        tourLoto(nbHasard,carton1,carton2,carton3,nbTiresJ1,nbTiresJ2,nbTiresJ3);
        checkScores(nbTiresJ1, nbTiresJ2,nbTiresJ3,points,&nbPhases); //check les scores a chaque tour et affiche si quine/double quine/bingo
        if (nbPhases != 3)
        {
            affichePoints(points);
            affichCartons(carton1,carton2,carton3);
            printf("Nombre tir%c : %d \n", 130, nbHasard);
            getchar();
        }
        //saveDonnees();
        system("cls");
    }
    int vainqueur = comptePoints(points);
    afficheScores(vainqueur, points);
    getchar();
    return 0;
}
