#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "case.h"

void creerCaseDefaut(Case *p)
{

}

void creerCase(Case *p, int valeur)
{

}

void modifValeur(Case *p, int newVal)
{
    p->valeur = newVal;
}

void modifestTiree(Case *p, int newestTiree)
{
    p->estTiree = newestTiree;
}

void afficheValeur(Case *p)
{
    return p->valeur;
}

void afficheCase(Case *p)
{

}

int valeurCase(Case *p)
{

}

int estTireeCase(Case *p)
{

}
