#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menuLoto.h"

int main()
{
    srand(time(NULL));
    menuDemarrage(); //affichage du menu de démarrage
/*
    for(int i=0;i<3;i++){
       creerCarton(); //creation de 3 cartons
    }

    while("personne n'a fait bingo"){
        tourLoto(); //affichage d'un tour de jeu
        menuPartie(); //affichage du menu de jeu (quitter et save,pause,continuer)
    }
    comptePoints(); //compte les points et définit le vainqueur
    return 0;
    */
}
