#ifndef TIRAGES_H_INCLUDED
#define TIRAGES_H_INCLUDED

int suppElemPos(int tab[],int pos,int taille);
void affichTab (int tab[],int N);
int estDansTab(int tab[],int val,int taille);
void triBulle(int tab[],int taille);
void tirageCol(int nbValCol[]);
void tirageLig(int nbValCol[], int carton[][9]);
void tirageNb(int nbValCol[],int listeVal[]);


#endif // TIRAGES_H_INCLUDED
