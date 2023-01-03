#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "case.h"
#include <windows.h>
#include <dos.h>
#include <dir.h>
#define asciibloc 219
#define asciiligne 179

#define asciihaut 220
#define asciibas 223

//---------------fonctions niveau 1-----------------//
void setColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}


void suppElemPos(int tab[],int pos,int taille)
{
    for (int i=pos;i<taille-1;i++)
    {
        assert(i>=0 && i<taille);
        tab[i]=tab[i+1];
    }
}

void tirageCol(int nbValCol[])
{
    int liste[10]={0,1,2,3,4,5,6,7,8,8};
    int tailleListe=10,iHasard,nbHasard;

    while(tailleListe>4)
    {
        iHasard=rand()%(tailleListe+1);

        nbHasard=liste[iHasard];

        nbValCol[nbHasard]++;

        suppElemPos(liste,iHasard,tailleListe);
        tailleListe--;
    }
}

void copieTab(int tab1[],int tab2[],int taille)
{
    for(int i=0;i<taille;i++)
    {
        tab2[i]=tab1[i];
    }
}

void suppElemVal(int tab[],int val,int taille)
{
    int x = tab[0];
    int i=1;
    while(x!=val)
    {
        x=tab[i];
        i++;
    }
    suppElemPos(tab,i-1,taille);
}

void tirageLig(int nbValCol[], Case carton[][9])
{
    int cpt;
    for(int ligne=0;ligne<3;ligne++)
    {
        int colNonTirees[9]={0,1,2,3,4,5,6,7,8};
        int taille=9;
        cpt=0;
        for(int col=0;col<9;col++)
        {
            if(nbValCol[col]==(3-ligne))
            {
                modifestTiree(&carton[ligne][col], 1);
                nbValCol[col] = nbValCol[col] - 1;
                suppElemVal(colNonTirees,col,taille);
                taille--;
                cpt++;
            }
        }
        int hasard, colHasard;
        while (cpt!=5)
        {
            hasard=rand()%(taille);
            colHasard=colNonTirees[hasard];
            if (nbValCol[colHasard]!=0)
            {
                modifestTiree(&carton[ligne][colHasard], 1);
                nbValCol[colHasard] = nbValCol[colHasard] - 1;
                suppElemVal(colNonTirees,colHasard,taille);
                taille--;
                cpt++;
            }
        }
    }
}

int estDansTab(int tab[],int val,int taille)
{
    int i=0;
    while(tab[i]!=val && i<taille)
    {
        i++;
    }
    if(i==taille)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void tirageNb(int nbValCol[], int listeVal[])
{
    int val,compteur=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<nbValCol[i];j++)
        {
            val=rand()%(10)+i*10;
            while(val==0 || estDansTab(listeVal,val,compteur)==1)
            {
                val=rand()%(10)+i*10;
            }
            listeVal[compteur]=val;
            compteur++;
        }
    }
}

void triBulle(int tab[],int taille)
{
    int trie=0, memTemporaire;
    while (trie==0)
    {
        trie=1;
        for(int i=0;i<taille-1;i++)
        {
            if(tab[i]>tab[i+1])
            {
                memTemporaire=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=memTemporaire;
                trie=0;
            }
        }
    }
}

void injecteVal(Case carton[][9], int listeVal[])
{
    int cpt=0;
    for(int col=0;col<9;col++)
    {
        for(int ligne=0;ligne<3;ligne++)
        {
            if(estTireeCase(&carton[ligne][col]) == 1)
            {
                modifValeur(&carton[ligne][col], listeVal[cpt]);
                cpt++;
            }
        }
    }
}
//---------------------fonctions de création des cartons------------------------------------//

void affichCarton(Case tab[][9], int numJoueur)
{
    setColor(numJoueur + 2);
    for(int i=0;i<37;i++)
    {
        printf("%c",asciihaut);
    }
    printf("\n");
    for(int i=0;i<3;i++)
    {
        setColor(numJoueur + 2);
        printf("%c",asciibloc);
        setColor(0);
        for(int j=0;j<9;j++)
        {
            int val = valeurCase(&tab[i][j]);
            if(estTireeCase(&tab[i][j]) == 0)
            {
                setColor(numJoueur + 2);
                if (j == 0){
                    printf("%c%c%c", asciibloc,asciibloc, asciibloc);
                }
                else{
                    printf("%c%c%c%c", asciibloc, asciibloc, asciibloc, asciibloc);
                }
                setColor(0);
            }
            else if (estTireeCase(&tab[i][j]) == 1)
            {
                printf(" %d ",val);
            }
            else if (estTireeCase(&tab[i][j]) == 2)
            {
                setColor(numJoueur + 2);
                printf(" %d ", val);
                setColor(0);
            }
        }
        setColor(numJoueur + 2);
        printf("%c",asciibloc);
        setColor(0);
        printf("\n");
    }
    setColor(numJoueur + 2);
    for(int i=0;i<37;i++)
    {
        printf("%c",asciibas);
    }
    setColor(0);
    printf("\n");
}

void affichCartons(Case carton1[][9], Case carton2[][9], Case carton3[][9])
{
        printf("Joueur 1 :\n");
        affichCarton(carton1, 31);


        printf("\nJoueur 2 :\n");
        affichCarton(carton2, 2);
        printf("\nJoueur 3 :\n");
        affichCarton(carton3, 3);
        printf("\n");
}

void creerCarton(Case carton[][9])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            modifValeur(&carton[i][j], 0);
            modifestTiree(&carton[i][j], 0);
        }
    }
}

void creerCartons(Case carton1[][9], Case carton2[][9], Case carton3[][9])
{
    creerCarton(carton1);
    creerCarton(carton2);
    creerCarton(carton3);
}

void modifCarton(Case carton[][9])
{
    int nbValCol[9]={1,1,1,1,1,1,1,1,1};

    int listeVal[15]={0};

    tirageCol(nbValCol);

    int nbValCol2[9];
    copieTab(nbValCol,nbValCol2,9);

    tirageLig(nbValCol,carton);

    tirageNb(nbValCol2,listeVal);
    triBulle(listeVal,15);

    injecteVal(carton,listeVal);
}

void modifCartons(Case carton1[][9], Case carton2[][9], Case carton3[][9])
{
    modifCarton(carton1);
    modifCarton(carton2);
    modifCarton(carton3);
}

//-------------------------------fonctions de tirage----------------------------------------//

void checkNbDansCarton(Case carton[][9],int scoreJ[][1], int nb)
{
   for (int i = 0; i < 3; i++)
   {
       for(int j = 0; j < 9; j++)
       {
           if(valeurCase(&carton[i][j]) == nb)
           {
               scoreJ[i][0]++;
               modifestTiree(&carton[i][j], 2);
           }
       }
   }
}

/*
 *  int i = 0;
    int j = 0;
    while (i < 3 && valeurCase((&carton[i][j])) != nb)
    {
        while (j < 9 && valeurCase(&carton[i][j]) != nb)
        {
            j++;
        }
        i++;
    }
    if(i < 3 && j < 9)
    {
        modifestTiree(&carton[i][j], 2);
        scoreJ[i][0] += 1;
    }
 */
