#include "case.h"
#include "tirages.h"
#include "save_import.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

#define asciimur 186
#define asciiligne 205
#define asciicoinhautgauche 201
#define asciicoinhautdroite 187
#define asciicoinbasgauche 200
#define asciicoinbasdroite 188


void initCartons(Case carton1[][9], Case carton2[][9], Case carton3[][9])
{
    creerCartons(carton1,carton2,carton3);

    modifCartons(carton1, carton2, carton3);
}

void remplirListe(int liste[])
{
    for (int i = 0;i < 90; i++)
    {
        liste[i] = i+1;
    }
}

void recupNbTires(Case carton1[][9], Case carton2[][9], Case carton3[][9], int nbTiresJ1[3][1], int nbTiresJ2[3][1],int nbTiresJ3[3][1])
{
    //import nbTires du carton 1
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(estTireeCase(&carton1[i][j]) == 2)
            {
                nbTiresJ1[i][0]++;
            }
        }
    }
    //import nbTires du carton 2
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(estTireeCase(&carton2[i][j]) == 2)
            {
                nbTiresJ2[i][0]++;
            }
        }
    }

    //import nbTires du carton 3
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(estTireeCase(&carton3[i][j]) == 2)
            {
                nbTiresJ3[i][0]++;
            }
        }
    }
}

void recupListeTirage(int listeNbTires[], int tailleListeTires, int listeTirage[])
{
    int cpt = 0;
    for(int i = 1; i <= 90; i++)
    {
        int test = 0;
        for(int j = 0; j < tailleListeTires; j++)
        {
            if(i == listeNbTires[j])
            {
                test = 1;
            }
        }
        if (test == 0)
        {
            listeTirage[cpt] = i;
            cpt++;
        }
    }
}

void bingo(int numGagnant)
{
    system("color 10");
            sleep(0.7);
            system("color 40");
            sleep(0.7);
            system("color 50");
            sleep(0.7);
            system("color 10");
            sleep(0.7);
            system("color 40");
            sleep(0.7);
            system("color 50");
            sleep(0.7);
            system("color 10");
            sleep(0.7);
            system("color 40");
            sleep(0.7);
            system("color 00");
            sleep(1);
            for(int i = 0; i < 40; i++)
            {
                if(i%2 == 0 && numGagnant == 1)
                {
                    system("color 16");
                }
                else if(i%2 == 1 && numGagnant == 1)
                {
                    system("color 1F");
                }

                else if(i%2 == 0 && numGagnant == 2)
                {
                    system("color 46");
                }
                else if(i%2 == 1 && numGagnant == 2)
                {
                    system("color 4F");
                }

                else if(i%2 == 0 && numGagnant == 3)
                {
                    system("color 56");
                }
                else
                {
                    system("color 5F");
                }

                printf("BBBBBBBBBBBBBBBBB  IIIIIIIIINNNNNNNN        NNNNNNNN       GGGGGGGGGGGGG    OOOOOOOOO         OOOOOOOOO         OOOOOOOOO           !!!\n");
                printf("B::::::::::::::::B I::::::::N:::::::N       N::::::N    GGG::::::::::::G  OO:::::::::OO     OO:::::::::OO     OO:::::::::OO        !!:!!\n");
                printf("B::::::BBBBBB:::::BI::::::::N::::::::N      N::::::N  GG:::::::::::::::GOO:::::::::::::OO OO:::::::::::::OO OO:::::::::::::OO      !:::!\n");
                printf("BB:::::B     B:::::II::::::IN:::::::::N     N::::::N G:::::GGGGGGGG::::O:::::::OOO:::::::O:::::::OOO:::::::O:::::::OOO:::::::O     !:::!\n");
                printf("  B::::B     B:::::B I::::I N::::::::::N    N::::::NG:::::G       GGGGGO::::::O   O::::::O::::::O   O::::::O::::::O   O::::::O     !:::!\n");
                printf("  B::::B     B:::::B I::::I N:::::::::::N   N::::::G:::::G             O:::::O     O:::::O:::::O     O:::::O:::::O     O:::::O     !:::!\n");
                printf("  B::::BBBBBB:::::B  I::::I N:::::::N::::N  N::::::G:::::G             O:::::O     O:::::O:::::O     O:::::O:::::O     O:::::O     !:::!\n");
                printf("  B:::::::::::::BB   I::::I N::::::N N::::N N::::::G:::::G    GGGGGGGGGO:::::O     O:::::O:::::O     O:::::O:::::O     O:::::O     !:::!\n");
                printf("  B::::BBBBBB:::::B  I::::I N::::::N  N::::N:::::::G:::::G    G::::::::O:::::O     O:::::O:::::O     O:::::O:::::O     O:::::O     !:::!\n");
                printf("  B::::B     B:::::B I::::I N::::::N   N:::::::::::G:::::G    GGGGG::::O:::::O     O:::::O:::::O     O:::::O:::::O     O:::::O     !:::!\n");
                printf("  B::::B     B:::::B I::::I N::::::N    N::::::::::G:::::G        G::::O:::::O     O:::::O:::::O     O:::::O:::::O     O:::::O     !!:!!\n");
                printf("  B::::B     B:::::B I::::I N::::::N     N:::::::::NG:::::G       G::::O::::::O   O::::::O::::::O   O::::::O::::::O   O::::::O      !!!\n");
                printf("BB:::::BBBBBB::::::II::::::IN::::::N      N::::::::N G:::::GGGGGGGG::::O:::::::OOO:::::::O:::::::OOO:::::::O:::::::OOO:::::::O\n");
                printf("B:::::::::::::::::BI::::::::N::::::N       N:::::::N  GG:::::::::::::::GOO:::::::::::::OO OO:::::::::::::OO OO:::::::::::::OO       !!!\n");
                printf("B::::::::::::::::B I::::::::N::::::N        N::::::N    GGG::::::GGG:::G  OO:::::::::OO     OO:::::::::OO     OO:::::::::OO        !!:!!\n");
                printf("BBBBBBBBBBBBBBBBB  IIIIIIIIINNNNNNNN         NNNNNNN       GGGGGG   GGGG    OOOOOOOOO         OOOOOOOOO         OOOOOOOOO           !!!\n");
                sleep(0.8);
            }
            system("cls");
            system("color F0");
}

int recupPhase(int points[])
{
    int totalPts = points[0] + points[1] + points[2];
    if (totalPts == 0)
    {
        return 0;
    }

    else if (totalPts == 10)
    {
       return 1;
    }

    else if (totalPts == 30)
    {
        return 2;
    }

    else if (totalPts == 70)
    {
        return 3;
    }
}

int tirageNbHasard(int listeTirage[], int *tailleListe, int listeNbTires[], int *tailleListeTires)
{
    //Tirer le nombre
    int nbHasard = listeTirage[rand() % *tailleListe];
    suppElemVal(listeTirage,nbHasard,*tailleListe);
    *tailleListe = *tailleListe - 1;
    listeNbTires[*tailleListeTires] = nbHasard;
    *tailleListeTires = *tailleListeTires + 1;
    return nbHasard;
}

void affichePoints(int points[])
{
    printf("                                                                                                     SCORES          \n");
    printf("                                                                                            J1 : %d | J2 : %d | J3 : %d\n\n",points[0], points[1], points[2]);
}
void tourLoto(int nbHasard,Case carton1[][9], Case carton2[][9], Case carton3[][9], int scoreJ1[][1], int scoreJ2[][1], int scoreJ3[][1])
{
    //verifier chaque carton
        //si un carton contient ce nb, le marquer
        //sinon ne rien faire

    checkNbDansCarton(carton1, scoreJ1, nbHasard);
    checkNbDansCarton(carton2, scoreJ2, nbHasard);
    checkNbDansCarton(carton3, scoreJ3, nbHasard);
}

int checkScores(int scoreJ1[][1], int scoreJ2[][1], int scoreJ3[][1], int points[3], int *nbPhases)
{
    //scoreJX = tableau de 3 lignes et 1 colonne, chaque ligne correspond a la ligne du carton
    //premier a 1 ligne a 5 = quine -> points[x] += 10;
    //premier a 2 lignes a 5 = double quine -> points[x] += 20;
    //premier a 3 lignes a 5 = bingo -> points[x] += 40;
    //affiche a la fin du tour si quelqu'un a fait quine/double quine/bingo
    int numGagnant = 0;
    if (*nbPhases == 0)
    {
        if (scoreJ1[0][0] == 5 || scoreJ1[1][0] == 5 || scoreJ1[2][0] == 5)
        {
            *nbPhases += 1;
            points[0] += 10;
            printf("                                                                                      Joueur 1 a fait quine ! Il gagne 10 points.\n\n");
        }

        else if (scoreJ2[0][0] == 5 || scoreJ2[1][0] == 5 || scoreJ2[2][0] == 5)
        {
            points[1] += 10;
            *nbPhases += 1;
            printf("                                                                                      Joueur 2 a fait quine ! Il gagne 10 points.\n\n");
        }

        else if (scoreJ3[0][0] == 5 || scoreJ3[1][0] == 5 || scoreJ3[2][0] == 5)
        {
            points[2] += 10;
            *nbPhases += 1;
            printf("                                                                                      Joueur 3 a fait quine ! Il gagne 10 points.\n\n");
        }
    }

    else if (*nbPhases == 1)
    {
        if ((scoreJ1[0][0] == 5 && scoreJ1[1][0] == 5) || (scoreJ1[0][0] == 5 && scoreJ1[2][0] == 5) || (scoreJ1[1][0] == 5 && scoreJ1[2][0] == 5))
        {
            points[0] += 20;
            *nbPhases += 1;
            printf("                                                                                      Joueur 1 a fait double quine ! Il gagne 20 points.\n\n");
        }

        if ((scoreJ2[0][0] == 5 && scoreJ2[1][0] == 5) || (scoreJ2[0][0] == 5 && scoreJ2[2][0] == 5) || (scoreJ2[1][0] == 5 && scoreJ2[2][0] == 5))
        {
            points[1] += 20;
            *nbPhases += 1;
            printf("                                                                                      Joueur 2 a fait double quine ! Il gagne 20 points.\n\n");
        }

        if ((scoreJ3[0][0] == 5 && scoreJ3[1][0] == 5) || (scoreJ3[0][0] == 5 && scoreJ3[2][0] == 5) || (scoreJ3[1][0] == 5 && scoreJ3[2][0] == 5))
        {
            points[2] += 20;
            *nbPhases += 1;
            printf("                                                                                      Joueur 3 a fait double quine ! Il gagne 20 points.\n\n");
        }
    }

    else if (*nbPhases == 2)
    {
        if (scoreJ1[0][0] == 5 && scoreJ1[1][0] == 5 && scoreJ1[2][0] == 5)
        {
            points[0] += 40;
            *nbPhases += 1;
            numGagnant = 1;
            bingo(numGagnant);
            system("cls");
        }

        else if (scoreJ2[0][0] == 5 && scoreJ2[1][0] == 5 && scoreJ2[2][0] == 5)
        {
            points[1] += 40;
            *nbPhases += 1;
            numGagnant = 2;
            bingo(numGagnant);
            sleep(3);
            system("cls");
        }

        else if (scoreJ3[0][0] == 5 && scoreJ3[1][0] == 5 && scoreJ3[2][0] == 5)
        {
            points[2] += 40;
            *nbPhases += 1;
            numGagnant = 3;
            bingo(numGagnant);
            system("cls");
        }
    }
}


int comptePoints(int points[3])
{
    if(points[0] > points[1] && points[0] > points[2])
    {
        return 1;
    }

    else if(points[1] > points[0] && points[1] > points[2])
    {
        return 2;
    }

    else if(points[2] > points[0] && points[2] > points[1])
    {
        return 3;
    }
}

void afficheNbTires(int liste[], int tailleListe)
{
    printf("                                                                              Nombres Tir%cs : ", 130);
    for (int i = 0; i < tailleListe-1; i++)
    {
        if (i%14 == 0)
        {
            printf("\n                                                                              ");
        }
        printf("%d, ", liste[i]);
    }
    printf("%d\n", liste[tailleListe-1]);
}
