#ifndef LOTO_SAE_BIBLIOTHEQUE_H
#define LOTO_SAE_BIBLIOTHEQUE_H
void initCartons(Case carton1[][9], Case carton2[][9], Case carton3[][9]);
void remplirListe(int liste[]);
void recupNbTires(Case carton1[][9], Case carton2[][9], Case carton3[][9], int nbTiresJ1[3][1], int nbTiresJ2[3][1],int nbTiresJ3[3][1]);
int tirageNbHasard(int listeTirage[], int *tailleListe);
void bingo(int numGagnant);
void recupPhase(int points[], int *nbPhase);
void affichePoints(int points[]);
void tourLoto(int nbHasard,Case carton1[][9], Case carton2[][9], Case carton3[][9], int scoreJ1[][1], int scoreJ2[][1], int scoreJ3[][1]);
void checkScores(int scoreJ1[][1], int scoreJ2[][1], int scoreJ3[][1], int points[3], int *nbPhases);
int comptePoints(int points[3]);
void afficheScores(int vainqueur, int points[3]);
#endif //LOTO_SAE_BIBLIOTHEQUE_H
