#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "case.h"
#include "tirages.h"
#include "bibliotheque.h"
int main()
{
    srand(time(NULL));
    //menuDemarrage(); //affichage du menu de démarrage

    //creation de 3 cartons
    Case carton1[3][9];
    Case carton2[3][9];
    Case carton3[3][9];
    initCartons(carton1,carton2,carton3);

    //creation/remplissage de la liste de nombres
    int listeTirage[90]={0};
    int tailleListe = 90;
    remplirListe(listeTirage);

    //initialisation de variables utiles
    int points[3] = {0, 0, 0};
    int scoreJ1[3][1] = {{0},{0},{0}};
    int scoreJ2[3][1] = {{0},{0},{0}};
    int scoreJ3[3][1] = {{0},{0},{0}};
    int nbPhases = 0; //correspond au nb de phases deja faites (quine, bingo..)

    while(nbPhases != 3){
        affichCartons(carton1,carton2,carton3);
        int nbHasard = tirageNbHasard(listeTirage, &tailleListe);
        tourLoto(nbHasard,carton1,carton2,carton3,scoreJ1,scoreJ2,scoreJ3);
        checkScores(scoreJ1, scoreJ2,scoreJ3,points,&nbPhases); //check les scores a chaque tour et affiche si quine/double quine/bingo
        //menuPartie(); //affichage du menu de jeu (quitter et save,pause,continuer)

            /*tests
            printf("%d\n", nbHasard);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 1; j++) {
                    printf("%d ", scoreJ1[i][j]);
                    printf("%d ", scoreJ2[i][j]);
                    printf("%d ", scoreJ3[i][j]);
                }
                printf("\n");
            }
                for (int i = 0; i < tailleListe; i++)
                    printf("%d ", listeTirage[i]);
                printf("\n");
            */
        getchar();
    }
    int vainqueur = comptePoints(points);
    afficheScores(vainqueur, points);
    return 0;
}