#ifndef SAVE_IMPORT_H
#define SAVE_IMPORT_H

int lenTab(int tab[]);
void saveGrille(Case grille[][9],char mode[3]);
void saveInfoGame(int listeTirage,int tailleListe,int points[3]);
void recupereGrille(Case grille[3][9],int nLigne);
void RecupereGameInfo(int listeTirage,int points[3]);
int recupereTailleListe(int listeTirage[]);

#endif //SAVE_IMPORT_H
