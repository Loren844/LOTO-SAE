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
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cL%cO%cT%cO%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",asciicoinhautgauche,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciicoinhautdroite);
    printf("                                                                        %c                                                                                                   %c\n",asciimur,asciimur);
    printf("                                                                        %c                                  Bienvenue sur le jeu de Loto !                                   %c\n",asciimur,asciimur);
    printf("                                                                        %c                       Pour commencer, choisissez ce que vous voulez faire :                       %c\n",asciimur,asciimur);
    printf("                                                                        %c                                                                                                   %c\n",asciimur,asciimur);
    printf("                                                                        %c                               1) Commencer une nouvelle partie                                    %c\n",asciimur,asciimur);
    printf("                                                                        %c                            2) Reprendre a partir d'une sauvegarde                                 %c\n",asciimur,asciimur);
    printf("                                                                        %c                                                                                                   %c\n",asciimur,asciimur);
    printf("                                                                        %c   /!\\ La sauvegarde s'effectue a chaque tour, vous pouvez quitter la partie a tout moment. /!\\    %c\n",asciimur,asciimur);
    printf("                                                                        %c                                                                                                   %c\n",asciimur,asciimur);
    printf("                                                                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",asciicoinbasgauche,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciicoinbasdroite);
    printf("\n\n                                                                        Saisir votre reponse (1 ou 2): ");
    scanf("%d", &rep);
    while (rep != 1 && rep != 2)
    {
        printf("                                                                        Mauvaise saisie !\n");
        printf("                                                                        Saisir votre reponse (1 ou 2): ");
        scanf("%d", &rep);
    }
    return rep;
}

void afficheScores(int vainqueur, int points[3])
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cL%cO%cT%cO%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",asciicoinhautgauche,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciicoinhautdroite);
    printf("                                                                        %c                                                                                        %c\n",asciimur,asciimur);
    printf("                                                                        %c                                     SCORE FINAUX                                       %c\n",asciimur,asciimur);
    printf("                                                                        %c                                  Joueur 1 : %d points                                  ",asciimur,points[0]);
    if (points[0] < 10)
    {
        printf(" ");
    }
    printf("%c\n", asciimur);
    printf("                                                                        %c                                  Joueur 2 : %d points                                  ",asciimur,points[1]);
    if (points[1] < 10)
    {
        printf(" ");
    }
    printf("%c\n", asciimur);
    printf("                                                                        %c                                  Joueur 3 : %d points                                  ",asciimur,points[2]);
    if (points[2] < 10)
    {
        printf(" ");
    }
    printf("%c\n", asciimur);
    printf("                                                                        %c                       Le vainqueur est le Joueur %d ! Bravo a lui                       %c\n",asciimur,vainqueur,asciimur);
    printf("                                                                        %c                                                                                        %c\n",asciimur,asciimur);
    printf("                                                                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",asciicoinbasgauche,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciiligne,asciicoinbasdroite);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
