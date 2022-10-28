#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


int menuDemarrage()
{
    int rep;
    printf("----------------------------------------L-O-T-O-------------------------------------------\n");
    printf("|                                                                                        |\n");
    printf("|                             Bienvenue sur le jeu de Loto !                             |\n");
    printf("|                  Pour commencer, choisissez ce que vous voulez faire :                 |\n");
    printf("|                                                                                        |\n");
    printf("|                          1) Commencer une nouvelle partie                              |\n");
    printf("|                        2) Reprendre a partir d'une sauvegarde                          |\n");
    printf("|                                                                                        |\n");
    printf("------------------------------------------------------------------------------------------\n");
    printf("Saisir votre reponse (1 ou 2): ");
    scanf("%d", &rep);
    while (rep != 1 && rep != 2) {
        printf("Tu sais pas lire ??\n");
        printf("Saisir votre reponse (1 ou 2): ");
        scanf("%d", &rep);
    }
}

//menu qui demandera après chaque tour si le joueur veut arreter et save sa partie
    int menuPartie() {
        int rep;
        printf("----------------------------------------L-O-T-O-------------------------------------------\n");
        printf("|                                                                                        |\n");
        printf("|                                                                                        |\n");
        printf("|                           Voulez-vous faire une pause ?(o/n)                           |\n");
        printf("|                  (La partie sera sauvegardee ne vous en faites pas !)                  |\n");
        printf("|                                                                                        |\n");
        printf("|                                                                                        |\n");
        printf("------------------------------------------------------------------------------------------\n");
        printf("Saisir votre réponse : ");
        scanf("%c", &rep);
        if (rep == 'o') {
            rep = 1;
        }
        else {
            rep = 0;
        }
}
