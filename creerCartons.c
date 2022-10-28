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

void creerCarton()
{
    int nbValCol[9]={1,1,1,1,1,1,1,1,1};
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


    //tirage au sort des emplacements/lignes

    int carton[3][9]={{0}};

    for(int ligne=0;ligne<3;ligne++)
    {
        int cpt=0;
        for(int col=0;col<9;col++)
        {
            printf("%d\n",3-ligne);
            printf("%d\n",nbValCol[col]);
            if(nbValCol[col]==(3-ligne))
            {
                printf("baise\n\n");
                carton[ligne][col]=1;
                //printf("%d\n",nbValCol[col]);
                nbValCol[col]--;
                //printf("%d\n",nbValCol[col]);
                cpt++;
            }
        }
        int colHasard;
        while (cpt!=5)
        {
            colHasard=rand()%(9);
            if (nbValCol[colHasard]!=0)
            {
                carton[ligne][col]=1;
                nbValCol[colHasard]--;
                cpt++;
            }
        }
    }

    affichCarton(carton);

    // tirage au sort des nombres

    int listeVal[15],val,cpt=0;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<nbValCol[i];j++)
        {
            val=rand()%(10)+i*10;

            while(val==0 || estDansTab(listeVal,val,cpt)==1)
            {
                val=rand()%(10)+i*10;
            }

            listeVal[cpt]=val;
            cpt++;
        }
    }

    triBulle(listeVal,15);
    //affichTab(listeVal,15);


}
