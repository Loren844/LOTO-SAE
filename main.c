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

    Case carton1[3][9];
    Case carton2[3][9];
    Case carton3[3][9];
    initCartons(carton1,carton2,carton3); //creation de 3 cartons

    affichCartons(carton1,carton2,carton3);

    int listeTirage[89]={0};
    remplirListe(listeTirage);

    //while("personne n'a fait bingo"){
        //tourLoto(); //affichage d'un tour de jeu
        //menuPartie(); //affichage du menu de jeu (quitter et save,pause,continuer)
    //}
    //comptePoints(); //compte les points et définit le vainqueur

    return 0;
}

