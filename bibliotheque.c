#include "case.h"
#include "tirages.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int tirageNbHasard(int listeTirage[], int *tailleListe)
{
    //Tirer le nombre
    srand(time(NULL));
    int nbHasard = listeTirage[rand() % *tailleListe];
    *tailleListe = tailleListe - 1;
    return nbHasard;
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
    if (*nbPhases == 0)
    {
        if (scoreJ1[0][0] == 5 || scoreJ1[1][0] == 5 || scoreJ1[2][0] == 5)
        {
            points[0] += 10;
            *nbPhases++;
            printf("Joueur 1 a fait quine ! Bravo à lui ");
        }

        else if (scoreJ2[0][0] == 5 || scoreJ2[1][0] == 5 || scoreJ2[2][0] == 5)
        {
            points[1] += 10;
            *nbPhases++;
            printf("Joueur 2 a fait quine ! Bravo à lui ");
        }

        else if (scoreJ3[0][0] == 5 || scoreJ3[1][0] == 5 || scoreJ3[2][0] == 5)
        {
            points[2] += 10;
            *nbPhases++;
            printf("Joueur 3 a fait quine ! Bravo à lui ");
        }
    }

    else if (*nbPhases == 1)
    {
        if ((scoreJ1[0][0] == 5 && scoreJ1[1][0] == 5) || (scoreJ1[0][0] == 5 && scoreJ1[2][0] == 5) || (scoreJ1[1][0] == 5 && scoreJ1[2][0] == 5))
        {
            points[0] += 20;
            *nbPhases++;
            printf("Joueur 1 a fait double quine ! Bravo à lui ");
        }

        if ((scoreJ2[0][0] == 5 && scoreJ2[1][0] == 5) || (scoreJ2[0][0] == 5 && scoreJ2[2][0] == 5) || (scoreJ2[1][0] == 5 && scoreJ2[2][0] == 5))
        {
            points[1] += 20;
            *nbPhases++;
            printf("Joueur 2 a fait double quine ! Bravo à lui ");
        }

        if ((scoreJ3[0][0] == 5 && scoreJ3[1][0] == 5) || (scoreJ3[0][0] == 5 && scoreJ3[2][0] == 5) || (scoreJ3[1][0] == 5 && scoreJ3[2][0] == 5))
        {
            points[2] += 20;
            *nbPhases++;
            printf("Joueur 3 a fait double quine ! Bravo à lui ");
        }
    }

    else if (*nbPhases == 2)
    {
        if (scoreJ1[0][0] == 5 && scoreJ1[1][0] == 5 && scoreJ1[2][0] == 5)
        {
            points[0] += 40;
            *nbPhases++;
            printf("Joueur 1 a fait bingo ! Bravo à lui ");
        }

        else if (scoreJ2[0][0] == 5 && scoreJ2[1][0] == 5 && scoreJ2[2][0] == 5)
        {
            points[1] += 40;
            *nbPhases++;
            printf("Joueur 2 a fait bingo ! Bravo à lui ");
        }

        else if (scoreJ3[0][0] == 5 && scoreJ3[1][0] == 5 && scoreJ3[2][0] == 5)
        {
            points[2] += 40;
            *nbPhases++;
            printf("Joueur 3 a fait bingo ! Bravo à lui ");
        }
    }
}

void menuPartie()
{
    //affiche le menu
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

void afficheScores(int vainqueur, int points[3])
{

    /*
    si 70
        joueur a 70 a tout fait
    si 60
        joueur a 60 a fait bingo et double quine
        joueur a 10 a fait quine
    si 50
        joueur a 50 a gagné bingo quine
        joueur a 20 a fait double quine
    si 40
        joueur a 40 a gagné bingo
        si 30
            joueur a 30 a fait quine et double
        sinon
            joueur a 20 a fait double
            joueur a 10 a fait quine

    bravo a meilleur score
     */

    //Joueur 1 : 20 points
    //Joueur 2 : 10 points
    //Joueur 3 : 40 points
    //Le vainqueur est le Joueur 3 ! Bravo à lui
}
