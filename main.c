#include <stdio.h>
#include <stdlib.h>
#include<allegro.h>
#include "biblio2.h"

int main()
{


    lancerToutAllegro(800,600);//lancement de allegro
    BITMAP*tabbit[20];// on declare notre tableau de bitmap
    remplirtabbit(tabbit);// apelle du sous programme pour le remplire
    int tabmap[20][20];// tableau de fond de la map
    remplirtabmap(tabbit,tabmap);// appelle du sous programme pour le remplir
    int choix;// variable choix
    choix=0;//initialisation de la variable
    int niv=1;//on declare et initialise la variable niveau a 1
    int j;
    while(choix!=3)
    {

        choix=menu();// appelle du sous programme menu

        if (choix==1)
        {
            jeu(tabbit, tabmap, niv);// lancement du jeu si choix=1
            choix=0;//ré-initialisation de la variable
        }
        if(choix==2)
        {
            aide();
            choix=0;
        }
        if(choix==4)
        {
            niv=choixniv();//apelle du sous programme de choix des niveaux
            if(niv==1)
            {
                j=niv1(tabbit,tabmap);// on apelle le sous prgramme du niveau 1
                if(j==1)
                {
                    niv=niv+1;// niv prend plus 1 pour passer automatiquement au niveau suivant
                }
                if(j==0)
                {
                    niv=0;
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
                    niv=0;
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
                    j=niv3(tabbit,tabmap);
                }
                if(j==0)
                {
                    niv=0;
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
                    niv=0;
                }

            }
        }
        if(choix==3)
        {
            allegro_exit();// quitter allegro si choix=3
        }
    }

return 0;
} END_OF_MAIN();
