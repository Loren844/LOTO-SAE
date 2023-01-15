#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "case.h"

int lenTab(int tab[])
{
    return sizeof(tab) / sizeof(tab[0]);
}

//save
void saveGrille(Case grille[][9],char mode[3])
{
    FILE* fichier = NULL;
    fichier = fopen("stockStruc.txt",mode);
    if(fichier !=NULL)
    {
        for(int k = 0 ; k < 3 ; k++)
        {
            for(int l = 0 ; l < 9 ; l++)
            {
                fprintf(fichier,"%d %d;",valeurCase(&grille[k][l]),estTireeCase(&grille[k][l]));
            }
        }
        fprintf(fichier,"\n");
        fclose(fichier);
    }
}

void saveInfoGame(int *listeTirage,int tailleListe,int points[3])
{
    FILE* fichier = NULL;
    fichier = fopen("stockStruc.txt","a");
    if(fichier !=NULL)
    {
        for(int i = 0 ; i < tailleListe ; i++)
        {
            fprintf(fichier,"%d;",listeTirage[i]);
        }
        fprintf(fichier,"\n");
        for(int j = 0 ; j < 3 ; j++)
        {
            fprintf(fichier,"%d;",points[j]);
        }
        fclose(fichier);
    }
}

//import
void recupereGrille(Case grille[3][9],int nLigne)
{
    FILE* fichier = NULL;
    int i=0,j=0,k=1;
    int value = 0;
    char ligne[256];
    fichier = fopen("stockStruc.txt","r");
    for(int k = 1 ; k < nLigne ; k++)
    {
        while (fgetc(fichier) != '\n');
    }
    fgets(ligne, sizeof(ligne), fichier);
    const char * separators = " ;";
    char * strToken = strtok ( ligne, separators );
    while(strToken!=NULL)
    {
        value = atoi(strToken);
        if(k%2==0)
        {
            modifestTiree(&grille[i][j], value);
            j++;
            if(j%9==0)
            {
                i++;
                j=0;
            }
        } else if(k%2==1)
        {
            modifValeur(&grille[i][j], value);
        }
        strToken = strtok ( NULL, separators );
        k++;
    }
    fclose(fichier);
}

void recupereGameInfo(int *listeTirage,int tailleListe,int points[3])
{
    FILE* fichier = NULL;
    int value = 0;
    char ligne[256];
    int i = 0;
    int j = 0 ;
    fichier = fopen("stockStruc.txt","r");
    for(int k = 1 ; k < 4 ; k++)
    {
        while (fgetc(fichier) != '\n');
    }
    fgets(ligne, sizeof(ligne), fichier);
    const char * separators = ";";
    char * strToken = strtok ( ligne, separators );
    while(strToken!=NULL) {
        value = atoi(strToken);
        listeTirage[i] = value;
        strToken = strtok ( NULL, separators );
        i++;
    }
    fgets(ligne, sizeof(ligne), fichier);
    const char * separators2 = ";";
    char * strToken2 = strtok ( ligne, separators );
    while (strToken2 != NULL)
    {
        printf("%d", atoi(strToken2));
        points[j] = atoi(strToken2);
        strToken2 = strtok ( NULL, separators );
        j++;
    }
    fclose(fichier);
}
