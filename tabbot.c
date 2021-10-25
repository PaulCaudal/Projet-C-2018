#include"biblio2.h"
#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>
int debug(int pos,int j)//
{
    if(j==1)//bot
    {
        if(pos==0)
            return 16;
        if(pos==1)
            return 19;
        if(pos==2)
            return 17;
        if(pos==-1)
            return 18;
    }
    if(j==2)
    {
        if(pos==0)
            return 2;
        if(pos==1)
            return 10;
        if(pos==2)
            return 8;
        if(pos==-1)
            return 9;
    }
}

void remplirtabbotn3(BITMAP* tabbit[20],int tab[10],int s)//ce sous programme affiche la sequence de deplacement du bot et complete sont tableau
{
    int k=450;
    if(s==1)
    {
        masked_blit(tabbit[4],tabbit[0],0,0,k,50,tabbit[4]->w,tabbit[4]->h);
        k=k+65;
        masked_blit(tabbit[4],tabbit[0],0,0,k,50,tabbit[4]->w,tabbit[4]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[4],tabbit[0],0,0,k,50,tabbit[4]->w,tabbit[4]->h);
        k=450;
        masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[6],tabbit[0],0,0,k,110,tabbit[6]->w,tabbit[6]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        tab[0]=1;
        tab[1]=1;
        tab[2]=3;
        tab[3]=3;
        tab[4]=1;
        tab[5]=3;
        tab[6]=3;
        tab[7]=3;
        tab[8]=2;
        tab[9]=3;
    }
    if(s==2)
    {
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[4],tabbit[0],0,0,k,50,tabbit[4]->w,tabbit[4]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[6],tabbit[0],0,0,k,50,tabbit[6]->w,tabbit[6]->h);
        k=450;
        masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        tab[0]=3;
        tab[1]=1;
        tab[2]=3;
        tab[3]=3;
        tab[4]=2;
        tab[5]=3;
        tab[6]=3;
        tab[7]=0;
        tab[8]=0;
        tab[9]=0;

    }
}
void remplirtabbotn4(BITMAP* tabbit[20],int tab[10],int s)
{
    int k=450;
    if(s==1)
    {
        masked_blit(tabbit[4],tabbit[0],0,0,k,50,tabbit[4]->w,tabbit[4]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=450;
        masked_blit(tabbit[6],tabbit[0],0,0,k,110,tabbit[6]->w,tabbit[6]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        tab[0]=1;
        tab[1]=3;
        tab[2]=3;
        tab[3]=3;
        tab[4]=3;
        tab[5]=2;
        tab[6]=3;
        tab[7]=3;
        tab[8]=3;
        tab[9]=3;

    }
    if(s==2)
    {
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[4],tabbit[0],0,0,k,50,tabbit[4]->w,tabbit[4]->h);
        k=k+65;

        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=450;

         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[6],tabbit[0],0,0,k,110,tabbit[6]->w,tabbit[6]->h);
        k=k+65;
        tab[0]=3;
        tab[1]=1;
        tab[2]=3;
        tab[3]=3;
        tab[4]=3;
        tab[5]=3;
        tab[6]=3;
        tab[7]=3;
        tab[8]=3;
        tab[9]=2;
    }
    if(s==3)
    {

        masked_blit(tabbit[4],tabbit[0],0,0,k,50,tabbit[4]->w,tabbit[4]->h);
        k=k+65;

        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=450;

         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
        masked_blit(tabbit[6],tabbit[0],0,0,k,110,tabbit[6]->w,tabbit[6]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[7],tabbit[0],0,0,k,110,tabbit[7]->w,tabbit[7]->h);
        k=k+65;

        tab[0]=3;
        tab[1]=3;
        tab[2]=3;
        tab[3]=1;
        tab[4]=3;
        tab[5]=3;
        tab[6]=2;
        tab[7]=3;
        tab[8]=3;
        tab[9]=3;
    }
    if(s==4)
    {
         masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[4],tabbit[0],0,0,k,50,tabbit[4]->w,tabbit[4]->h);
        k=k+65;


        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        k=k+65;
         masked_blit(tabbit[6],tabbit[0],0,0,k,50,tabbit[6]->w,tabbit[6]->h);
        k=k+65;
        masked_blit(tabbit[7],tabbit[0],0,0,k,50,tabbit[7]->w,tabbit[7]->h);
        tab[0]=3;
        tab[1]=1;
        tab[2]=3;
        tab[3]=2;
        tab[4]=3;
        tab[5]=0;
        tab[6]=0;
        tab[7]=0;
        tab[8]=0;
        tab[9]=0;
    }
}

void demitourbot(BITMAP* tabbit[20], int*pos, int*x, int*y, int g,int xp, int yp)//il recoit les bitmap, la position de perso
{
    int xf2;
    int yf2;

    xf2=132;
    yf2=112;
    if(*pos==0)//orienter a gaughe
    {
        masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);//carte
        masked_blit(tabbit[16],tabbit[0],0,0,*x,*y,tabbit[16]->w,tabbit[16]->h);//perso
        masked_blit(tabbit[g],tabbit[0],0,0,xp,yp,tabbit[g]->w,tabbit[g]->h);//on affiche le perso
        masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);//fruit
        draw_sprite(screen,tabbit[0],0,0);
        rest(100);
    }
    if(*pos==1)//haut
    {
        masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
        masked_blit(tabbit[19],tabbit[0],0,0,*x,*y,tabbit[19]->w,tabbit[19]->h);
        masked_blit(tabbit[g],tabbit[0],0,0,xp,yp,tabbit[g]->w,tabbit[g]->h);
        masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
        draw_sprite(screen,tabbit[0],0,0);
        rest(100);
    }
    if(*pos==2)//droit
    {
        masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
        masked_blit(tabbit[17],tabbit[0],0,0,*x,*y,tabbit[17]->w,tabbit[17]->h);
        masked_blit(tabbit[g],tabbit[0],0,0,xp,yp,tabbit[g]->w,tabbit[g]->h);
        masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
        draw_sprite(screen,tabbit[0],0,0);
        rest(100);
    }
    if(*pos==-1)//bas
    {
        masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
        masked_blit(tabbit[18],tabbit[0],0,0,*x,*y,tabbit[18]->w,tabbit[18]->h);
        masked_blit(tabbit[g],tabbit[0],0,0,xp,yp,tabbit[g]->w,tabbit[g]->h);
        masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
        draw_sprite(screen,tabbit[0],0,0);
        rest(100);
    }
}

int liretabbot(BITMAP*tabbit[20],int tab[10], int*x,int* y,int*xtab,int*ytab,int*pos, int xf, int yf, int g, int xp, int yp)   //ce sous programme fait ce deplacer le bot
{
    int j, p, v;
    v=0;
    int xf2;
    int yf2;

    xf2=132;
    yf2=112;

    for(j=0; j<10; j++)
    {

        if(tab[j]==1 || tab[j]==2)//si le deplacement est un quart de tour alors
        {
            *pos=position(&*pos, tab[j]);//on appelle le sous programme de positionement
        }
        demitourbot(tabbit, &*pos, &*x, &*y,g, xp, yp);//on affiche les quart de tour



        masked_blit(tabbit[g],tabbit[0],0,0,xp,yp,tabbit[g]->w,tabbit[g]->h);

        rest(100);
        if(tab[j]==3)
        {
            v=0;
        }
        if(tab[j]!=3)
        {
            v=1;
        }
        if(*pos==2 && v==0)//mouvement a droite
        {

            *xtab=*xtab+1;//on modifie les coordoné map du personnage
            for(p=0; p<11; p++)//boucle pour avoir un mouvement fluide
            {
                *x=*x+2;//legere augmentation
                masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);//carte
                masked_blit(tabbit[g],tabbit[0],0,0,xp,yp,tabbit[g]->w,tabbit[g]->h);//on affiche le perso
                masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);//fruit
                masked_blit(tabbit[17],tabbit[0],0,0,*x,*y,tabbit[17]->w,tabbit[17]->h);//perso
                draw_sprite(screen,tabbit[0],0,0);//affichage
                rest(20);
            }

        }
        if(*pos==-1 && v==0)//bas
        {
            *ytab=*ytab+1;
            for(p=0; p<11; p++)
            {
                *y=*y+2;
                masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
                masked_blit(tabbit[g],tabbit[0],0,0,xp,yp,tabbit[g]->w,tabbit[g]->h);
                masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
                masked_blit(tabbit[18],tabbit[0],0,0,*x,*y,tabbit[18]->w,tabbit[18]->h);
                draw_sprite(screen,tabbit[0],0,0);
                rest(20);
            }

        }
        if(*pos==0 && v==0)//gauche
        {
            *xtab=*xtab-1;
            for(p=0; p<11; p++)
            {
                *x=*x-2;
                masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
                masked_blit(tabbit[g],tabbit[0],0,0,xp,yp,tabbit[g]->w,tabbit[g]->h);
                masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
                masked_blit(tabbit[16],tabbit[0],0,0,*x,*y,tabbit[16]->w,tabbit[16]->h);
                draw_sprite(screen,tabbit[0],0,0);
                rest(20);
            }

        }
        if(*pos==1 && v==0)//haut
        {
            *ytab=*ytab-1;
            for(p=0; p<11; p++)
            {
                *y=*y-2;
                masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
                masked_blit(tabbit[g],tabbit[0],0,0,xp,yp,tabbit[g]->w,tabbit[g]->h);
                masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
                masked_blit(tabbit[19],tabbit[0],0,0,*x,*y,tabbit[19]->w,tabbit[19]->h);
                draw_sprite(screen,tabbit[0],0,0);
                rest(20);
            }


        }
        if(tab[j]==0)
        {
            return 0;//on arrete la boucle si rein ne suis
        }
        if(*xtab==xf && *ytab==yf)//si les coordonnées map du perso et du fruit sont les meme
        {
            return 2;//alors on retourne 1
        }
    }
    for(j=0; j<10; j++)//remise a 0 du tableau de deplacement
    {
        tab[j]=0;
    }
    return 0;//on retourne 0 si l'bjectif n'a pas été atteind

}
