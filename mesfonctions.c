
#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <dos.h>
#include <dir.h>

/// /////////////////////////////////////////////////////////////////////// ///
/// Proc�dure pour changer l'affichage du texte dans la console             ///
/// 0 : noir        4 : rouge       8  : gris fonc�     12 : rouge clair    ///
/// 1 : bleu        5 : magenta     9  : bleu clair     13 : magenta clair  ///
/// 2 : vert        6 : brun        10 : vert clair     14 : jaune          ///
/// 3 : cyan        7 : gris clair  11 : cyan clair     15 : blanc          ///
/// source de cette fonction : https://askcodez.com/comment-changer-la-     ///
/// couleur-du-texte-et-de-la-console-de-couleur-dans-codeblocks.html       ///
/// /////////////////////////////////////////////////////////////////////// ///


void affichecarton(int T1[],int T2[],int T3[]){
    int i;
    for (i=0;i<9;i++){
        printf("%d  ",T1[i]);
    }
    printf("\n");
    for (i=0;i<9;i++){
        printf("%d  ",T2[i]);
    }
    printf("\n");
    for (i=0;i<9;i++){
        printf("%d  ",T3[i]);
    }
    printf("\n");


}
void creecarton(int T1[],int T2[],int T3[]){
    int i=0,x1,x2,quelleligne1,quelleligne2,vabaisser,compt_col_actuel=10,j,compt_ligne_1=5,compt_ligne_2=5,compt_ligne_3=5,compt_col=3;
    srand( time( NULL ) );
    while (compt_ligne_1>0 && compt_ligne_2>0 && compt_ligne_3>0){
        if (compt_col!=0){

            vabaisser=rand()%3;
            if (vabaisser==0){
                compt_col--;
                x1 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
                if (x1==0){
                    x1 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
                }
                quelleligne1=rand()%3;
                if (quelleligne1==0){
                    T1[i]=x1;
                    compt_ligne_1--;
                }
                else if (quelleligne1==1){
                    T2[i]=x1;
                    compt_ligne_2--;
                }
                else if (quelleligne1==2){
                    T3[i]=x1;
                    compt_ligne_3--;
                }
            }
            else {
                x1 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
                x2 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
                while ((x1>=x2) || (x1==0) ){
                    x2=x1;
                    x1 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
                }
                quelleligne1=rand()%3;
                if (quelleligne1==0){
                    T2[i]=x1;
                    T3[i]=x2;
                    compt_ligne_2--;
                    compt_ligne_3--;
                }
                else if (quelleligne1==1){
                    T1[i]=x1;
                    T3[i]=x2;
                    compt_ligne_1--;
                    compt_ligne_3--;
                }
                else if (quelleligne1==2){
                    T1[i]=x1;
                    compt_ligne_1--;
                    T2[i]=x2;
                    compt_ligne_2--;
                }
            }
        }
    i++;
    compt_col_actuel=compt_col_actuel+10;
    }

affichecarton(T1,T2,T3);
while (compt_ligne_1>0 || compt_ligne_2>0 || compt_ligne_3>0){
    if ((compt_col>0) && compt_col==9-i){
        if (compt_ligne_1==0 && compt_ligne_2==0){
            x1=rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            T3[i]=x1;
            compt_ligne_3--;
            compt_col--;
        }
        else if (compt_ligne_2==0 && compt_ligne_3==0){
            x1=rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            T1[i]=x1;
            compt_ligne_1--;
            compt_col--;
        }
        else if (compt_ligne_1==0 && compt_ligne_3==0){
            x1=rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            T2[i]=x1;
            compt_ligne_2--;
            compt_col--;
        }
    }
    else {
        if (compt_ligne_1==0){
            x1 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            x2 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            while ((x1>=x2) || (x1==0) ){
                x2=x1;
                x1 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            }
            T2[i]=x1;
            compt_ligne_2--;
            T3[i]=x2;
            compt_ligne_3--;
        }
        else if (compt_ligne_2==0){
            x1 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            x2 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            while ((x1>=x2) || (x1==0) ){
                x2=x1;
                x1 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            }
            T1[i]=x1;
            compt_ligne_1--;
            T3[i]=x2;
            compt_ligne_3--;
        }

        else if (compt_ligne_3==0){
            x1 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            x2 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            while ((x1>=x2) || (x1==0) ){
                x2=x1;
                x1 = rand()% (compt_col_actuel - (compt_col_actuel-10)) + compt_col_actuel-10;
            }
            T1[i]=x1;
            compt_ligne_1--;
            T2[i]=x2;
            compt_ligne_2--;
        }
    }
i++;
compt_col_actuel=compt_col_actuel+10;

}
affichecarton(T1,T2,T3);
}

void setColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
                 //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

int minimum (int nb1, int nb2)
{
    if (nb1<=nb2)
        return nb1 ;
    return nb2 ;
}

int maximum (int nb1, int nb2)
{
    if (nb1>=nb2)
        return nb1 ;
    return nb2 ;
}

int saisieEntier (int borneInf, int borneSup)
{
    int nb ;
    printf("Veuillez saisir un entier compris entre %d et %d\n", borneInf, borneSup) ;
    scanf ("%d", &nb) ;
    while ( (nb<borneInf) || (nb>borneSup) )
    {
        printf("Veuillez saisir un entier compris entre %d et %d\n", borneInf, borneSup) ;
        scanf ("%d", &nb) ;
    }
    return nb ;
}


void ligne(char char1, int color,int large)
{
    int nombre=large,i;
    setColor(color);
    for (i=0;i<nombre;i++){
        printf("%c",char1);
    }

}

void rectangle(char char1,int longu, int large)
{
    int i;
    for (i=0;i<=large;i++){
        int couleur=rand()%16;
        ligne(char1,couleur,large);
        printf("\n");
    }
}
void triangle_rectangle(char char1, int large)
{
    int i;
    for (i=0;i<=large;large--){
        int couleur=rand()%16;
        ligne(char1,couleur,large);
        printf("\n");
    }
}

int puissance(int nombre, int puiss)
{
    int resultat=nombre,i;
    if (puiss==0){
        resultat=1;
        return resultat;

    }
    for (i=1;i<puiss;i++)
        resultat=resultat*nombre;
    return resultat;
}


void afficherEntier (char message [], int val)
{
    printf("%s %d\n", message, val) ;
}

void returnSigneMultiplication(int int1,int int2)
{
    if (((int1<=0) && (int2<=0)) || ((int1>=0)&& (int2>=0))){
        printf("le resultat de la multiplication est positif\n");
    }
    else {
        printf("le resultat de la multiplication est negatif\n");
    }
}


int nombreParfait(int int1)
{
    int resultat, i;
    for (i; resultat>int1;i++){
        if (int1==resultat){
            return 1;
        }
        resultat=resultat+i;
    }
    return 0;
}

int argentbancaire(int int1)
{
    int compte=0,i;
    for (i=0;i<=int1;i++){
        compte=compte+100+(2*i);
    }
    return compte;


}
void sommeCubes(int nbmax)
{
    for(int i=0;i<=nbmax;i++)
    {
        int nb=i,s=0,add;
        while((nb%10!=0)||(nb/10!=0))
        {
            add=puissance(nb%10,3);
            s=s+add;
            nb=nb/10;
        }
        if (s==i)
        {
            printf("%d\n",i);
        }
    }
}
void initTablauRandom(int tab[], int taille, int valMax)
{


    int i ;
    srand(time(NULL));
    for (i=0;i<taille;i++){
        tab[i]=rand() % (valMax+1);
    }
}

void afficheTableau1D(int T[],int taille){
    int i;
    for (i=0;i<taille;i++){
        printf("t[%d] = %d\n",i,T[i]);
    }
}


int positionPremiereValeur(int T[], int taille,int NbrRechercher){
    int i;
    for (i=0;i<taille;i++){
        if (T[i]==NbrRechercher){
            return i;
        }
    }
    return -1;
}
int nombreDeValeurDansTabelau(int T[], int taille,int NbrRechercher){
    int i,total=0;
    for (i=0;i<taille;i++){
        if (T[i]==NbrRechercher){
            total++;
            }
    }
    return total;
}
int TabelauCroissant(int T[], int taille){
    int i;
    for (i=0;i<taille-1;i++){
        if (T[i]>=T[i+1]){
                return -1;
            }
    }
    return 0;
}
int minimumTableau(int T[], int taille){
    int i,mini;
    mini=T[0];
    for (i=1;i<taille;i++){
        if (T[i]<=mini){
                mini=T[i];

            }
    }
    return mini;
}
int minimumTableauPos(int T[], int taille){
    int i,mini,pos;
    mini=T[0];
    for (i=1;i<taille;i++){
        if (T[i]<mini){
                mini=T[i];
                pos=i;
            }
    }
    return pos;
}
int calcMoyenneTab(int T[], int taille){
    int i;
    float moy=0;
    for (i=1;i<taille;i++){
        moy=moy+T[i];
    }
    moy=moy/i;
    return moy;
}
void afficheTableau2D(int T[][5], int large, int longu){
    int i,j;
    for (i=0;i<large;i++){
        for (j=0;j<longu;j++){
            printf("%d ",T[i][j]);
        }
    printf("\n");
    }


}
int valeurminiTableau2D(int T[][5], int large, int longu){
    int i,j;
    int mini;
    mini=T[0][0];
    for (i=0;i<large;i++){
        for (j=0;j<longu;j++){
            if(mini>T[i][j]){
                mini=T[i][j];
            }
        }
    }
    return mini;

}
int nombrevaleurTableau2D(int T[][5], int large, int longu,int recherche){
    int i,j;
    int compt=0;
    for (i=0;i<large;i++){
        for (j=0;j<longu;j++){
            if(T[i][j]==recherche){
                compt++;
            }
        }
    }
    return compt;

}
int plusGrandEcart(int T[], int taille){
    int i,bornmin,bornmax,ecart;
    bornmin=T[0];
    bornmax=T[0];
    for (i=1;i<taille;i++){
        if(T[i]<bornmin){
            bornmin=T[i];
        }
        if(T[i]>bornmax){
            bornmax=T[i];
        }
    }
    ecart=bornmax-bornmin;
    return ecart;
}
void fusionne(int T1[],int taille1, int T2[], int taille2,int T3[]){
    int i=0,j=0,val=0,compt=0;

    while(i<taille1 && j<taille2){

        if (T1[i]>T2[j]){
            val=T2[j];
            j++;
        }
        else{
            val=T1[i];
            i++;
        }
        T3[compt]=val;
        compt++;
    }
    if (i<taille1){
        while(i<taille1){
            T3[compt]=T1[i];
            compt++;
            i++;
        }
    }
    if (j<taille1){
        while(j<taille1){
            T3[compt]=T1[j];
            compt++;
            j++;
        }
    }
}

int palindrome(char T1[],int taille){
    int i;
    for (i=0;i<taille/2;i++){


        if (T1[i]!=T1[taille-i]){
            return 0;
        }
    }
    return -1;

}

int suppElemPos(int T1[],int taille,int elementasupr, int nombrevaleurasupr){
    int i;
    if (taille==0){
        printf("Le tableau est vide");
    }
    else if (elementasupr>taille){
        printf("Cette element n'existe pas");
    }

    else {
        for (i=elementasupr;i<taille-1;i++){
            T1[i]=T1[i+1];

        }
        afficheTableau1D(T1,taille-nombrevaleurasupr);
    }

}


int InsererValeur(int T1[],int taille,int valeur, int pos){
    int i, valeurmemoire;
    if (taille==0){
        printf("Le tableau est vide");
    }
    else if (pos>taille){
        printf("Cette element n'existe pas");
    }

    else {
        int i = taille - 1;
        while(i >= pos) {
            T1[i + 1] = T1[i];
            if (i == pos) {
                T1[i] = valeur;
            }
            i--;
        }
    }
    afficheTableau1D(T1,taille+1);
}

int InsererValeurTableauTrier(int T1[],int taille,int valeur){
    int i, pos;
    if (taille==0){
        printf("Le tableau est vide");
    }
    else {
        for (i=0;i<taille;i++){
            if (T1[i]>=valeur){
                printf("test");
                pos=i;
                InsererValeur(T1,taille,valeur,pos);
                afficheTableau1D(T1,taille+1);
                return 0;
            }
        }
    }
}

int recherchedichotomique (int T1[],int taille,int valeur){
    int min,max,mil;
    while (min<max){
        mil=(min+max)%2;
        if (T1[mil]==valeur){
            return mil;
        }
        else {
            if (T1[mil]<valeur){
                min=mil;
            }
            else {
                max=mil;
            }
        }
        afficheTableau1D(T1,max-min);
    }
    return -1;
}
