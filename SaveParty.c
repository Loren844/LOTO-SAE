//Faire les imports necessaire dans le main.
void saveDonnees(Case grille[3][9])
{
    FILE* fichier = NULL;
    fichier = fopen("stockStruc.txt","w");
    if(fichier !=NULL)
    {
        for(int k = 0 ; k < 3 ; k++)
        {
            for(int l = 0 ; l < 9 ; l++)
            {
                fprintf(fichier,"%d %d;",grille[k][l].val,grille[k][l].estTiree);
            }
        }
        fprintf(fichier,"\n");
        fclose(fichier);
    }
}

void importDonnees(Case grille[3][9])
{
    FILE* fichier = NULL;
    int i=0,j=0,k=1;
    int value = 0;
    char ligne[256];
    fichier = fopen("stockStruc.txt","r");
    fgets(ligne, sizeof(ligne), fichier);
    const char * separators = " ;";
    char * strToken = strtok ( ligne, separators );
    while(strToken!=NULL)
    {
        if(k%2==0)
        {
            (&grille[i][j])->val = value;
            j++;
            if(j%9==0)
            {
                i++;
                j=0;
            }
        } else
        {
            (&grille[i][j])->estTiree = value;
        }
        value = atoi(strToken);
        strToken = strtok ( NULL, separators );
        k++;
    }
}
