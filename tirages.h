#ifndef TIRAGES_H_INCLUDED
#define TIRAGES_H_INCLUDED

//-----fonctions de niveau 1------//
void setColor(int ForgC);
void suppElemPos(int tab[],int pos,int taille);
void tirageCol(int nbValCol[]);
void copieTab(int tab1[],int tab2[],int taille);
void suppElemVal(int tab[],int val,int taille);
void tirageLig(int nbValCol[], Case carton[][9]);
int estDansTab(int tab[],int val,int taille);
void tirageNb(int nbValCol[], int listeVal[]);
void triBulle(int tab[],int taille);
void injecteVal(Case carton[][9], int listeVal[]);

//-----fonctions de création des cartons-----//
void affichCarton(Case tab[][9], int numJoueur);
void affichCartons(Case carton1[][9], Case carton2[][9], Case carton3[][9]);

void creerCarton(Case carton[][9]);
void creerCartons(Case carton1[][9], Case carton2[][9], Case carton3[][9]);

void modifCarton(Case carton[][9]);
void modifCartons(Case carton1[][9], Case carton2[][9], Case carton3[][9]);

//--------fonctions de tirage--------//
void remplirListe(int liste[]);


#endif // TIRAGES_H_INCLUDED
