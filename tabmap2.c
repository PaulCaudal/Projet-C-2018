#include"biblio2.h"
#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>
// ce sous programme remplie un tableau de blindage pour la carte
void remplirtabmap (BITMAP* tabbit[20], int tab[20][20])
{
    //pour le remplisage autaumatique on utilise des getpixel
    int x=11;//coordoné de depart pour les gatpixel
    int y=11;
    int i, j;// variable pour les boucle
    int r=makecol(238,238,238);// r prend la valeur du blanc qui est sur la carte
    int c;
    masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);// on colle la carte sur le buffer
    draw_sprite(screen,tabbit[0],0,0);//on affiche le buffer sur l'ecran
    for (i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            c=getpixel(screen,x,y);//c prend la valeur du getpixel au coordonnées x, y
            if(c!=r)
            {
                tab[i][j]=1;//si la case n'est pas blanche alors la case du tableau correspondant prend la valeur 1
            }
            else
            {
                tab[i][j]=0;//sinon elle prend la valeur 0
            }
            x=x+22;// xprend la valeur x+22 pour parcourire toute la ligne
        }
        y=y+22 ;//y prend la valeur y+22 pour parcourire toutes les colones
        x=11;//on remet x a 11
    }
    //apres avoir observé un defaillance sur les lignes 11, 14, 16, 17 et 19 on a "forcer" le blindage
    y=251;//on plce le y au centre de la case
    x=11;//on remet x a 11
    for(i=0; i<20; i++)//on parcour toute la ligne et on procede de la meme facon que pour le reste
    {
        c=getpixel(screen,x,y);
        if(c!=r)
        {
            tab[11][i]=1;
        }
        else
        {
            tab[11][i ]=0;
        }
        x=x+22;
    }
    //on fait la meme chose pour les autres ligne ou le blindage ne marcher pas
    y=314;
    x=11;
    for(i=0; i<20; i++)
    {
        c=getpixel(screen,x,y);
        if(c!=r)
        {
            tab[14][i]=1;
        }
        else
        {
            tab[14][i ]=0;
        }
        x=x+22;
    }
    y=360;
    x=11;
    for(i=0; i<20; i++)
    {
        c=getpixel(screen,x,y);
        if(c!=r)
        {
            tab[16][i]=1;
        }
        else
        {
            tab[16][i ]=0;
        }
        x=x+22;
    }
    y=380;
    x=11;
    for(i=0; i<20; i++)
    {
        c=getpixel(screen,x,y);
        if(c!=r)
        {
            tab[17][i]=1;
        }
        else
        {
            tab[17][i ]=0;
        }
        x=x+22;
    }
    y=425;
    x=11;
    for(i=0; i<20; i++)
    {
        c=getpixel(screen,x,y);
        if(c!=r)
        {
            tab[19][i]=1;
        }
        else
        {
            tab[19][i ]=0;
        }
        x=x+22;
    }

}
//sous programme qui verifie que la case ou le personnage veut aller est libre
int verif(int tabmap[20][20], int*x,int*y, int *c)//on lui transmet le tableau de blindage,les coordonées du perso dans le tableau, et le mouvement que il souhaite faire

{
    if(*c==2)//mouvement droit
    {
        if(tabmap[*y][*x+1]==0)
        {
            return 0;//on retourne 0 si la case est libre
        }
        else
        {
            return 1;//et 1 si il y a un arbre
        }
    }
    if(*c==-1)//mouvement en bas
    {
        if(tabmap[*y+1][*x]==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if(*c==0)//a gauche
    {
        if(tabmap[*y][*x-1]==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if(*c==1)//en haut
    {
        if(tabmap[*y-1][*x]==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return 1;
}
