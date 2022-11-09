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

void suppElemPos(int tab[],int pos,int taille)
{
    for (int i=pos;i<taille-1;i++)
    {
        assert(i>=0 && i<taille);
        tab[i]=tab[i+1];
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

void copieTab(int tab1[],int tab2[],int taille)
{
    for(int i=0;i<taille;i++)
    {
        tab2[i]=tab1[i];
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

void tirageLig(int nbValCol[], int carton[][9])
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
                *(*(carton+ligne)+col)=1;
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
                *(*(carton+ligne)+colHasard)=1;
                nbValCol[colHasard] = nbValCol[colHasard] - 1;
                suppElemVal(colNonTirees,colHasard,taille);
                taille--;
                cpt++;
            }
        }
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

void remplace1(int carton[][9], int listeVal[])
{
    int cpt=0;
    for(int col=0;col<9;col++)
    {
        for(int ligne=0;ligne<3;ligne++)
        {
            if( *(*(carton+ligne)+col) == 1)
            {
                *(*(carton+ligne)+col)=listeVal[cpt];
                cpt++;
            }
        }
    }
}

void creeCarton(int carton[][9])
{
    int nbValCol[9]={1,1,1,1,1,1,1,1,1};

    int listeVal[15]={0};

    tirageCol(nbValCol);

    int nbValCol2[9];
    copieTab(nbValCol,nbValCol2,9);

    tirageLig(nbValCol,carton);

    tirageNb(nbValCol2,listeVal);
    triBulle(listeVal,15);

    remplace1(carton,listeVal);
}


