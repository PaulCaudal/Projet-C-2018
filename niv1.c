#include"biblio2.h"
#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>
//ce sous programme est le niveau 1 le but est de d'atteindre le fruit
int niv1(BITMAP* tabbit[20], int tabmap[20][20])
{

    int tab[10];// tableau qui enregistre les mouvemet selectionné
    BITMAP*victoire;// declaration d'une bitmap
    victoire=load_bitmap("victoire.bmp",NULL);// chargement de cette bitmap
    if(!victoire)
    {
        allegro_message("pas pu trouver/ charger earth.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    int x=195;// coordonés en pixel du point de depart
    int y=239;
    int xtab=9;// coordonné dans le tableau d'arriére plan
    int ytab=11;
    int x1, y1;
    int d, r, h;
    h=0;// boucle de fin de jeu
    r=makecol(0,0,0);
    d=7;//d prend la valeur 7 car cet valeur n'a pas d'influence sur les evenements
    x1=0;// initialisation des coordoné du clic
    y1=0;
    int pos=0;// positionement(haut, bas , droit, gauche)
    int i=0;
    int k=15;// coordoné pour l'affichage
    int xf=6;// coordonné du fruit
    int yf=5;
    int n=1;//indique au sous programme lire tab de quelle niveau il s'agit pour le placement du fruit
    clear_to_color(screen,makecol(0,0,0));
    clear_to_color(tabbit[0],makecol(0,0,0));
    masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);//carte
    masked_blit(tabbit[3],tabbit[0],0,0,650,450,tabbit[3]->w,tabbit[3]->h);//boutons direction
    masked_blit(tabbit[5],tabbit[0],0,0,650,410,tabbit[5]->w,tabbit[5]->h);// quitter
    masked_blit(tabbit[2],tabbit[0],0,0,x,y,tabbit[2]->w,tabbit[2]->h);//perso
    masked_blit(tabbit[11],tabbit[0],0,0,132,112,tabbit[11]->w,tabbit[11]->h);//fruit
    masked_blit(tabbit[15],tabbit[0],0,0,560,410,tabbit[15]->w,tabbit[15]->h);//supprimé
    while(h==0)//boucle de jeu
    {


        if(mouse_b &1)//detection du clic
        {
            x1=mouse_x;//enregistement des coordonnées
            y1=mouse_y;
            mouse_b=0;
        }
        r=getpixel(tabbit[0],x1,y1);//saisi de la couleurs a l'endoit du clic
        d=compare(r);// on envoie ces valeur au programme de comparaison pour savoir quelle boutons a été selectionné
        if(d==5)//bouton quitter
        {
            return 0;
        }
        if(i<10 && d>=1 && d<=4)// si le bouton correspond a un deplacement alors on on rentre une valeur dans un tableau pour enregistrer le mouvement souhaité
        {
            remplirtab(tabbit,tab,k,i,d);// appelle du sous programme pour rempir le tableau
            i=i+1;// i prend +1 pour ne pas depasser 10
            k=k+65;//k prend +65, cette varible sert a l'affichage
        }
        if(d==6)// bouton supprimer
        {
            i=i-1;// on diminue i de 1
            if(i<0)
                i=0;// on blinde pour que i sois supérieur ue egale a 0
            tab[i]=0;
            k=k-65;// on diminue k de 65 pour garder un affichage cahérent
            if(k<15)
                k=15;// on blinde la meme maniere que pour i
            rectfill(tabbit[0],k,500,k+50,550,makecol(0,0,0));// on place un rectangle noir sur la commande qui a été annulé
        }
        if (d==0)//bouton exécution de la sequence
        {
            clear_to_color(tabbit[0],makecol(0,0,0));// on efface tout du buffer
            clear_to_color(screen,makecol(0,0,0));//on efface l'ecran
            masked_blit(tabbit[3],tabbit[0],0,0,650,450,tabbit[3]->w,tabbit[3]->h);// on reaffiche tout ce qui nous est necessaire
            masked_blit(tabbit[11],tabbit[0],0,0,132,112,tabbit[11]->w,tabbit[11]->h);
            masked_blit(tabbit[5],tabbit[0],0,0,650,410,tabbit[5]->w,tabbit[5]->h);
            masked_blit(tabbit[15],tabbit[0],0,0,560,410,tabbit[15]->w,tabbit[15]->h);
            draw_sprite(screen,tabbit[0],0,0);
            h=liretab(tabbit,tab,tabmap,&x,&y,&xtab,&ytab,&pos, xf, yf, n, 14,3,3);//appelle du sous prgramme d'exécution qui retourne une valeur pour savoir si l'objectife a été atteind
            i=0;// on re-initialise les varible i et k
            k=15;
        }
        x1=0;// on ré-initialise // les coordoné du clic précédent
        y1=0;
        r=makecol(0,0,0);
        d=7;
        draw_sprite(screen,tabbit[0],0,0);// on affiche le buffer a l'ecran
        rest(100);

    }
    clear_to_color(tabbit[0],makecol(0,0,0));// on netoie le buffer
    clear_to_color(screen,makecol(0,0,0));//on efface l'ecran
    masked_blit(victoire,tabbit[0],0,0,0,0,victoire->w,victoire->h);// on colle la bitmap sur le buffer
    draw_sprite(screen,tabbit[0],0,0);//on affiche le buffer a l'ecran
    x1=0;
    y1=0;
    rest(100);
    while(r!=makecol(163,73,164))//tant que le bouton suivant n'a pas été selectionné la boucle tourne
    {
        if(mouse_b &1)
        {
            x1=mouse_x;// on enregistre les coordonnées du clic
            y1=mouse_y;
            mouse_b=0;
        }
        r=getpixel(tabbit[0],x1,y1);//saisi de la couleur a l'endroit du clic
        if(r==makecol(163,73,164))// si la couleur corresond a makecol(163,73,164) alors on passe a la suite
        {
            return 1;
        }
    }
    return 0;
}
