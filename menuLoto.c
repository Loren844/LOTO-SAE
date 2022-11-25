#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define asciimur 186
#define asciiligne 205
#define asciicoinbasdroite 188
#define asciicoinbasgauche 200
#define asciicoinhautdroite 187
#define asciicoinhautgauche 201
int menuDemarrage()
{
    system("COLOR F0");
    int rep;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cL-O-T-O%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",asciicoinhautgauche,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciicoinhautdroite);
    printf("%c                                                                                        %c\n",asciimur,asciimur);
    printf("%c                             Bienvenue sur le jeu de Loto !                             %c\n",asciimur,asciimur);
    printf("%c                  Pour commencer, choisissez ce que vous voulez faire :                 %c\n",asciimur,asciimur);
    printf("%c                                                                                        %c\n",asciimur,asciimur);
    printf("%c                          1) Commencer une nouvelle partie                              %c\n",asciimur,asciimur);
    printf("%c                        2) Reprendre a partir d'une sauvegarde                          %c\n",asciimur,asciimur);
    printf("%c                                                                                        %c\n",asciimur,asciimur);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",asciicoinbasgauche,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciicoinbasdroite);
    char ch;


    return 0;
    printf("Saisir votre reponse (1 ou 2): ");
    scanf("%d", &rep);
    while (rep != 1 && rep != 2)
    {
        printf("Tu sais pas lire ??\n");
        printf("Saisir votre reponse (1 ou 2): ");
        scanf("%d", &rep);
    }
    getch();
    return 0;
}

//menu qui demandera après chaque tour si le joueur veut arreter et save sa partie
/*int menuPartie()
{
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
        if (rep == 'o')
        {
            rep = 1;
        }
        else
        {
            rep = 0;
        }
}
*/
