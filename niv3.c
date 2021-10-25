#include"biblio2.h"
#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>
//ce sous programme est le niveau 2 le but est de d'atteindre le fruit mais cette fois ci il y a un bot enemie
//ce sous progamme fonctionne de la meme maniére que le premier seul les instruction pour le bot seront commenter
int niv3(BITMAP* tabbit[20], int tabmap[20][20])
{

    int tab[10];
    BITMAP*victoire;
    BITMAP*gameover;
    victoire=load_bitmap("victoire.bmp",NULL);
    gameover=load_bitmap("gameover.bmp",NULL);
    if(!victoire)
    {
        allegro_message("pas pu trouver/ charger earth.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }if(!gameover)
    {
        allegro_message("pas pu trouver/ charger earth.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    int x=195;
    int y=239;
    int xtab=9;
    int ytab=11;
    int x1, y1;
    int d, r, h;
    int g=0;
    h=0;
    r=makecol(0,0,0);
    d=7;
    x1=0;
    y1=0;
    int pos=0;
    int posbot=0;//positionnement du bot
    int i=0;
    int k=15;
    int xf=6;
    int yf=5;
    int n=3;
    int xbot=0;//coordonné pixel du bot
    int ybot=0;
    int xb=0;//coordonnées tableau du bot
    int yb=0;
    int s=1;//sert pour savoir si le bot est a ca premiére ou a sa deuxieme sequence de deplacement
    int tabbot[10];
    clear_to_color(screen,makecol(0,0,0));
    clear_to_color(tabbit[0],makecol(0,0,0));
    masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
    masked_blit(tabbit[3],tabbit[0],0,0,650,450,tabbit[3]->w,tabbit[3]->h);
    masked_blit(tabbit[5],tabbit[0],0,0,650,410,tabbit[5]->w,tabbit[5]->h);
    masked_blit(tabbit[2],tabbit[0],0,0,x,y,tabbit[2]->w,tabbit[2]->h);
    masked_blit(tabbit[11],tabbit[0],0,0,132,112,tabbit[11]->w,tabbit[11]->h);
    masked_blit(tabbit[15],tabbit[0],0,0,560,410,tabbit[15]->w,tabbit[15]->h);
    masked_blit(tabbit[16],tabbit[0],0,0,xbot,ybot,tabbit[16]->w,tabbit[16]->h);//botgauche
    while(h==0)
    {

        if(s==1 || s==2)
        {
            remplirtabbotn3(tabbit,tabbot,s);
            s=0;
        }
        if(mouse_b &1)
        {
            x1=mouse_x;
            y1=mouse_y;
            mouse_b=0;
            r=getpixel(screen,x1,y1);
            d=compare(r);
        }
        if(d==5)
        {
            return 0;
        }
        if(i<10 && d>=1 && d<=4)
        {
            remplirtab(tabbit,tab,k,i,d);
            i=i+1;
            k=k+65;
        }
        if(d==6)
        {
            i=i-1;
            if(i<0)
                i=0;
            tab[i]=0;
            k=k-65;
            if(k<15)
                k=15;
            rectfill(tabbit[0],k,500,k+50,550,makecol(0,0,0));
        }
        if (d==0)
        {
            clear_to_color(tabbit[0],makecol(0,0,0));
            clear_to_color(screen,makecol(0,0,0));
            masked_blit(tabbit[3],tabbit[0],0,0,650,450,tabbit[3]->w,tabbit[3]->h);
            masked_blit(tabbit[11],tabbit[0],0,0,238,369,tabbit[11]->w,tabbit[11]->h);
            masked_blit(tabbit[5],tabbit[0],0,0,650,410,tabbit[5]->w,tabbit[5]->h);
            masked_blit(tabbit[15],tabbit[0],0,0,560,410,tabbit[15]->w,tabbit[15]->h);
            draw_sprite(screen,tabbit[0],0,0);
            g=debug(posbot,1);
            h=liretab(tabbit,tab,tabmap,&x,&y,&xtab,&ytab,&pos, xf, yf, n,g,xbot,ybot);
            g=debug(pos,2);
            if(h==0)
            {
                h=liretabbot(tabbit,tabbot,&xbot,&ybot,&xb,&yb,&posbot,xf,yf,g,x,y);
            }
            i=0;
            k=15;
            s=2;//on passe a la deuxieme sequance du bot
        }
        x1=0;
        y1=0;
        r=makecol(0,0,0);
        d=7;
        draw_sprite(screen,tabbit[0],0,0);
        rest(100);

    }
    clear_to_color(tabbit[0],makecol(0,0,0));
    clear_to_color(screen,makecol(0,0,0));
    if(h==1)

    {
        masked_blit(victoire,tabbit[0],0,0,0,0,victoire->w,victoire->h);
        draw_sprite(screen,tabbit[0],0,0);
    }
    if(h==2)
    {
        masked_blit(gameover,tabbit[0],0,0,0,0,gameover->w,gameover->h);
        draw_sprite(screen,tabbit[0],0,0);
    }
    x1=0;
    y1=0;
    while(r!=makecol(163,73,164))
    {
        if(mouse_b &1)
        {
            x1=mouse_x;
            y1=mouse_y;
            mouse_b=0;
        }
        r=getpixel(tabbit[0],x1,y1);
        if(r==makecol(163,73,164) && h==1)
        {
            return 1;
        }
        if(r==makecol(163,73,164) && h==2)
        {
            return 2;
        }
    }
    return 0;
}
