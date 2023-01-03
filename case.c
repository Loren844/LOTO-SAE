#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "case.h"


void creerCaseDefaut(Case *p)
{
    (*p).valeur = 0;
}

void creerCase(Case *p, int valeur)
{
    (*p).valeur = valeur;
}

void modifValeur(Case *p, int newVal)
{
    p->valeur = newVal;
}

void modifestTiree(Case *p, int newestTiree)
{
    p->estTiree = newestTiree;
}

void afficheCase(Case *p)
{
    printf("%d",(*p).valeur);
}

void affichEstTiree(Case *p)
{
    printf("%d",(*p).estTiree);
}

int valeurCase(Case *p)
{
    return (*p).valeur;
}

int estTireeCase(Case *p)
{
    return (*p).estTiree;
}
