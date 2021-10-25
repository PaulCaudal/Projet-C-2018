#include"biblio2.h"
#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>

void remplirtab(BITMAP* tabbit[8],int tab[10],int k, int i, int d)
{
    if(d==1)
    {
        tab[i]=1;
        masked_blit(tabbit[4],tabbit[0],0,0,k,500,tabbit[4]->w,tabbit[4]->h);
    }
    if(d==2)
    {
        tab[i]=2;
        masked_blit(tabbit[5],tabbit[0],0,0,k,500,tabbit[5]->w,tabbit[5]->h);
    }
    if(d==3)
    {
        tab[i]=3;
        masked_blit(tabbit[6],tabbit[0],0,0,k,500,tabbit[6]->w,tabbit[6]->h);
    }
    if(d==4)
    {
        tab[i]=4;
        masked_blit(tabbit[7],tabbit[0],0,0,k,500,tabbit[7]->w,tabbit[7]->h);
    }
    draw_sprite(screen,tabbit[0],0,0);
}


void liretab(BITMAP* tabbit[8],int tab[10],int tabmap[20][20], int*x ,int*y , int*xtab ,int*ytab)
{
    int j, p, v;
    for(j=0; j<10; j++)
    {
        v=verif(tabmap, &*xtab, &*ytab, tab[j]);
        if(tab[j]==1 && v==0)
        {


                for(p=0; p<11; p++)
                {
                    *x=*x+2;
                    masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
                    masked_blit(tabbit[2],tabbit[0],0,0,*x,*y,tabbit[2]->w,tabbit[2]->h);

                    draw_sprite(screen,tabbit[0],0,0);
                    rest(20);
                }

        }
        if(tab[j]==2)
        {
            //if(getpixel(tabbit[0],*x+10,*y+32)==makecol(238,238,238))
            {
                for(p=0; p<11; p++)
                {
                    *y=*y+2;
                    masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
                    masked_blit(tabbit[2],tabbit[0],0,0,*x,*y,tabbit[2]->w,tabbit[2]->h);

                    draw_sprite(screen,tabbit[0],0,0);
                    rest(20);
                }
            }
        }
        if(tab[j]==3)
        {
            //if(getpixel(tabbit[0],*x-13,*y+10)==makecol(238,238,238))
            {
                for(p=0; p<11; p++)
                {
                    *x=*x-2;
                    masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
                    masked_blit(tabbit[2],tabbit[0],0,0,*x,*y,tabbit[2]->w,tabbit[2]->h);

                    draw_sprite(screen,tabbit[0],0,0);
                    rest(20);
                }
            }
        }
        if(tab[j]==4)
        {
            //if(getpixel(tabbit[0],*x+10,*y-13)==makecol(238,238,238))
            {
                for(p=0; p<11; p++)
                {
                    *y=*y-2;
                    masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
                    masked_blit(tabbit[2],tabbit[0],0,0,*x,*y,tabbit[2]->w,tabbit[2]->h);

                    draw_sprite(screen,tabbit[0],0,0);
                    rest(20);
                }
            }
        }
    }
    for(j=0; j<10; j++)
    {
        tab[j]=0;
    }
}
