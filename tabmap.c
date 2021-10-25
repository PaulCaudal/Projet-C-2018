#include"biblio2.h"
#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>

void remplirtabmap (BITMAP* tabbit[8], int tab[20][20])
{
    int x=11;
    int y=11;
    int i, j;
    int r=makecol(238,238,238);
    int c;
    masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
    draw_sprite(screen,tabbit[0],0,0);
    for (i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            c=getpixel(screen,x,y);
            if(c!=r)
            {
                tab[i][j]=1;
            }
            else
            {
                tab[i][j]=0;
            }
            x=x+22;
        }
        y=y+22 ;
        x=11;
    }
    y=251; x=11;
    for(i=0;i<20;i++)
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
    y=314; x=11;
    for(i=0;i<20;i++)
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
    y=360; x=11;
    for(i=0;i<20;i++)
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
    y=380; x=11;
    for(i=0;i<20;i++)
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
    y=425; x=11;
    for(i=0;i<20;i++)
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

int verif(int tabmap[20][20], int*x ,int*y, int c)
{
    if(c==1)
    {
        if(tabmap[*x+1][*y]==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
