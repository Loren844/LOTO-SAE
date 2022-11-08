#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void affichTab (int tab[],int N)
{
    for(int i=0;i<N;i++)
    {
        printf("%d ",tab[i]);
    }
}

void affichCarton(int tab[][9])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<9;j++)
        {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

int suppElemPos(int tab[],int pos,int taille)
{
    for (int i=pos;i<taille-1;i++)
    {
        assert(i>=0 && i<taille);
        tab[i]=tab[i+1];
    }
    taille--;
    return taille;
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

void tirageLig(int nbValCol[], int p)
{
    int cpt;
    for(int ligne=0;ligne<3;ligne++)
    {
        printf("LIGNE %d\n",ligne+1);
        cpt=0;
        for(int col=0;col<9;col++)
        {
            if(nbValCol[col]==(3-ligne))
            {
                //carton[ligne][col]=1;
                //*(*(p+ligne)+col)=1;
                nbValCol[col] = nbValCol[col] - 1;
                cpt++;
            }
            int colHasard;
            while (cpt!=5)
            {
                colHasard=rand()%(9);
                if (nbValCol[colHasard]!=0)
                {
                    //carton[ligne][col]=1;
                    //*(*(p+ligne)+col)=1; //marche pas
                    nbValCol[colHasard] = nbValCol[colHasard] - 1;
                    cpt++;
                }
            }
        }
    }
}

void tirageNb(int nbValCol[], int listeVal[])
{
    int val,compteur;

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

