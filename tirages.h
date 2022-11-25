#ifndef TIRAGES_H_INCLUDED
#define TIRAGES_H_INCLUDED

int suppElemPos(int tab[],int pos,int taille);
void suppElemVal(int tab[],int val,int taille);
void affichTab (int tab[],int N);
int estDansTab(int tab[],int val,int taille);
void triBulle(int tab[],int taille);
void copieTab(int tab1[],int tab2[],int taille);
void tirageCol(int nbValCol[]);
void tirageLig(int nbValCol[], int carton[][9]); //a modifier void tirageLig(int nbValCol[], int *carton);
void tirageNb(int nbValCol[],int listeVal[]);
void remplace1(int carton[][9], int listeVal[]); // a modifier
void creerCarton(Case carton[][9]);
void affichCarton(Case tab[][9]);


#endif // TIRAGES_H_INCLUDED
