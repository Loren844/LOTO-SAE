#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED
typedef struct{
    int valeur;
    int estTiree;
    //0 = vide
    //1 = pas tirée
    //2 = tirée

} Case;



void creerCaseDefaut(Case *p);
void creerCase(Case *p, int valeur);
void modifValeur(Case *p, int newVal);
void modifestTiree(Case *p, int newestTiree);
int afficheValeur(Case *p);
void affichEstTiree(Case *p);
int valeurCase(Case *p);
int estTireeCase(Case *p);

#endif // CASE_H_INCLUDED
