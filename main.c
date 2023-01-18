#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "menuLoto.h"
#include "case.h"
#include "tirages.h"
#include "bibliotheque.h"
#include "save_import.h"

int main()
{
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    system("color F0");
    system("mode con cols=1080 lines=1920");
    srand(time(NULL));
    int dem = menuDemarrage(); //affichage du menu de démarrage

    //creation de 3 cartons
    Case carton1[3][9];
    Case carton2[3][9];
    Case carton3[3][9];

    //creation/remplissage de la liste de nombres
    int listeTirage[90] = {0};
    int tailleListe = 90;

    int listeNbTires[90] = {0};
    int tailleListeTires = 0;

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
        recupereGrille(carton1,1);
        recupereGrille(carton2,2);
        recupereGrille(carton3,3);
        recupereGameInfo(listeNbTires, points);
        tailleListeTires = recupereTailleListe(listeNbTires);

        recupListeTirage(listeNbTires, tailleListeTires, listeTirage);
        tailleListe = recupereTailleListe(listeTirage);
        recupNbTires(carton1, carton2, carton3, nbTiresJ1, nbTiresJ2, nbTiresJ3);
        nbPhases = recupPhase(points);
    }

    system("cls");
    getchar();

    while(nbPhases != 3)
    {
        int nbHasard = tirageNbHasard(listeTirage, &tailleListe, listeNbTires, &tailleListeTires);
        tourLoto(nbHasard,carton1,carton2,carton3,nbTiresJ1,nbTiresJ2,nbTiresJ3);
        checkScores(nbTiresJ1, nbTiresJ2,nbTiresJ3,points,&nbPhases); //check les scores a chaque tour et affiche si quine/double quine/bingo
        if (nbPhases != 3)
        {
            affichePoints(points);
            affichCartons(carton1,carton2,carton3);
            afficheNbTires(listeNbTires, tailleListeTires);
            printf("\n\n\n\n                                                                              Appuyez sur 'Entr%ce' pour continuer...\n",130);
            saveGrille(carton1,"w+");
            saveGrille(carton2,"a");
            saveGrille(carton3,"a");
            saveInfoGame(&listeNbTires,tailleListeTires, points);
            getchar();
        }
        //cette save permet de sauvegarder quand il y a bingo
        saveGrille(carton1,"w+");
        saveGrille(carton2,"a");
        saveGrille(carton3,"a");
        saveInfoGame(&listeNbTires,tailleListeTires, points);
        system("cls");
    }
    int vainqueur = comptePoints(points);
    afficheScores(vainqueur, points);
    getchar();
    return 0;
}

