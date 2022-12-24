#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "case.h"


void creerCaseDefaut(Case *p)
{
    (*p).val = 0;
}

void creerCase(Case *p, int valeur)
{
    (*p).val = valeur;
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
    //return p->valeur; c un void tu peux pas return tdc
}

void afficheCase(Case *p)
{
    printf("%d",(*p).val);
}

int valeurCase(Case *p)
{
    return (*p).val;
}

int estTireeCase(Case *p)
{
    return (*p).estTiree;
}
