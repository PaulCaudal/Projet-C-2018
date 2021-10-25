
#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>
#include"biblio2.h"
void jeu(BITMAP* tabbit[20], int tabmap[20][20], int niv)
{

    int j=1;//indice de fin de niveau (victoir, echec, quitter)
    while(j!=0)
    {

        if(niv==1)
        {
            j=niv1(tabbit,tabmap);// on apelle le sous prgramme du niveau 1
            if(j==1)
            {
                niv=niv+1;// niv prend plus 1 pour passer automatiquement au niveau suivant
            }
            if(j==0)
            {
                return 0;//retour au menu
            }
        }
        if(niv==2)
        {
            j=niv2(tabbit,tabmap);// on apelle le sous prgramme du niveau 2
            if(j==1)
            {
                niv=niv+1;// niv prend plus 1 pour passer automatiquement au niveau suivant
            }
            if(j==0)
            {
                return 0;//retour au menu
            }
        }
        if(niv==3)
        {
            j=niv3(tabbit,tabmap);// on apelle le sous prgramme du niveau 3
            if(j==1)
            {
                niv=niv+1;// niv prend plus 1 pour passer automatiquement au niveau suivant
            }
            if(j==2)
            {
                j=niv3(tabbit,tabmap);//on recommence si c'est perdu
            }
            if(j==0)
            {
                return 0;//retour au menu
            }
        }
        if(niv==4)
        {
            j=niv4(tabbit,tabmap);// on apelle le sous prgramme du niveau 3
            if(j==1)
            {
                niv=niv+1;// niv prend plus 1 pour passer automatiquement au niveau suivant
            }
            if(j==2)
            {
                j=niv4(tabbit,tabmap);
            }
            if(j==0)
            {
                return 0;
            }
        }
    }
}
