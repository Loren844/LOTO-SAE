#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED
typedef struct{
    int valeur;
    int estTiree;
} Case;

void creerCaseDefaut(int *p);
void creerCase(int *p, int valeur);
void modifValeur(int *p, int newVal);
void modifestTiree(int *p, int newestTiree);
void afficheCase(int *p);
int valeurCase(int *p);
int estTireeCase(int *p);

#endif // CASE_H_INCLUDED
