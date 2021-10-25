#include"biblio2.h"
#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>
//sous progamme qui remplie le tableau avec le mouvement selectioné et affiche ce mouvement
void remplirtab(BITMAP* tabbit[20],int tab[10],int k, int i, int d)//il recoit les bitmap, le tableau, k qui est la variable d'affichage, i la place dans le tableau et d le mouvement souhaiter
{
    if(d==1)//quart de tour droit
    {
        tab[i]=1;
        masked_blit(tabbit[4],tabbit[0],0,0,k,500,tabbit[4]->w,tabbit[4]->h);
    }
    if(d==2)//quart de tour gauche
    {
        tab[i]=2;
        masked_blit(tabbit[6],tabbit[0],0,0,k,500,tabbit[6]->w,tabbit[6]->h);
    }
    if(d==3)//avancé
    {
        tab[i]=3;
        masked_blit(tabbit[7],tabbit[0],0,0,k,500,tabbit[7]->w,tabbit[7]->h);
    }
    if(d==4)//cas ou le perso a la hache
    {
        tab[i]=4;
        masked_blit(tabbit[12],tabbit[0],0,0,k,500,tabbit[12]->w,tabbit[12]->h);//on affiche la hache
    }
    draw_sprite(screen,tabbit[0],0,0);
}
//sous programme qui attribue un entier en fonction du positionnement du perso
int position(int *pos, int c)//il recoit le pointeur sur cette entier, et le quart de tour selectionné
{
    if (c==1)//droit
    {
        *pos=*pos+1;//+1 vers la droite
    }
    if(c==2)//gauche
    {
        *pos=*pos-1;//-1 vers la gauche
    }
    if(*pos==-2)//on limite cette entier a 4 valeurs possible
    {
        *pos=2;//droite
    }
    if (*pos==3)
    {
        *pos=-1;//bas
    }
    if(*pos==-3)
    {
        *pos=1;//haut
    }
    if(*pos==4 || *pos==-4)
    {
        *pos=0;//gauche
    }
    return *pos;
}
//sous programme qui affiche les quart de tour et l'abre coupé si la hache est disponible
void demitour(BITMAP* tabbit[20], int i, int*pos, int xt, int yt, int*x, int*y, int n, int g, int xb, int yb)//il recoit les bitmap,i qui indique un arbre couper ou non, la position de perso, les coordonné ou affiché l'arbre coupé et les coordonnées du perso
{
    int xf2;
    int yf2;
    if(n==1 || n==3)//on fait en sorte que le fruit ne soit pas au meme endroit a chaque niveau
    {
        xf2=132;
        yf2=112;
    }
    if(n==2)
    {
        xf2=238;
        yf2=369;
    }
    if(*pos==0)//orienter a gaughe
    {
        masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);//carte
        if(i==1 || i==2)//indique si un arbre a été coupé
        {
            masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);//carré blance pour effacer l'arbre
        }
        masked_blit(tabbit[2],tabbit[0],0,0,*x,*y,tabbit[2]->w,tabbit[2]->h);//perso
        if(n==3)

        {
            masked_blit(tabbit[g],tabbit[0],0,0,xb,yb,tabbit[g]->w,tabbit[g]->h);//on affiche bien le bote si il y en a un
        }
        masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);//fruit
        draw_sprite(screen,tabbit[0],0,0);
        rest(100);
    }
    if(*pos==1)//haut
    {
        masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
        if(i==1 || i==2)
        {
            masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);
        }
        masked_blit(tabbit[10],tabbit[0],0,0,*x,*y,tabbit[10]->w,tabbit[10]->h);
        if(n==3)

        {
            masked_blit(tabbit[g],tabbit[0],0,0,xb,yb,tabbit[g]->w,tabbit[g]->h);
        }
        masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
        draw_sprite(screen,tabbit[0],0,0);
        rest(100);
    }
    if(*pos==2)//droit
    {
        masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
        if(i==1 || i==2)
        {
            masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);
        }
        masked_blit(tabbit[8],tabbit[0],0,0,*x,*y,tabbit[8]->w,tabbit[8]->h);
        if(n==3)

        {
            masked_blit(tabbit[g],tabbit[0],0,0,xb,yb,tabbit[g]->w,tabbit[g]->h);
        }
        masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
        draw_sprite(screen,tabbit[0],0,0);
        rest(100);
    }
    if(*pos==-1)//bas
    {
        masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
        if(i==1 || i==2)
        {
            masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);
        }
        masked_blit(tabbit[9],tabbit[0],0,0,*x,*y,tabbit[9]->w,tabbit[9]->h);
        if(n==3)

        {
            masked_blit(tabbit[g],tabbit[0],0,0,xb,yb,tabbit[g]->w,tabbit[g]->h);
        }
        masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
        draw_sprite(screen,tabbit[0],0,0);
        rest(100);
    }
}
//sous programme qui deplace le personnage et permet de coupé les arbres
int liretab(BITMAP* tabbit[20],int tab[10],int tabmap[20][20], int*x,int*y, int*xtab,int*ytab,int*pos, int xf,int yf, int n, int g, int xb, int yb)//il recoit les bitmap le tableau de deplacement les coordonné pixel et map du perso en pointeur et les coordonnées map du fruit
{
    int j, p, v, xt, yt, xtt, ytt;//variable pour les boucle et pour sauvegarder des coordonnées
    int i=0;
    int k=0;
    int xf2;
    int yf2;
    if(n==1 || n==3)//on fait en sorte que le fruit ne soit pas au meme endroit a chaque niveau
    {
        xf2=132;
        yf2=112;
    }
    if(n==2)
    {
        xf2=238;
        yf2=369;
    }
    for(j=0; j<10; j++)
    {

        if(tab[j]==1 || tab[j]==2)//si le deplacement est un quart de tour alors
        {
            *pos=position(&*pos, tab[j]);//on appelle le sous programme de positionement
        }
        if(tab[j]==3)//si l'ordre est d'avancer alors alors on verifie que le perso peut bien avancer
        {
            v=verif(tabmap, &*xtab, &*ytab, &*pos);// on apelle le sous programme de verification
        }
        if(tab[j]!=3)
        {
            v=1;
        }

        demitour(tabbit, i, &*pos, xt, yt, &*x, &*y, n,g,xb,yb);//on affiche les quart de tour
        rest(100);
        if(tab[j]==4)//si l'instruction est de coupé l'arbre
        {
            if(*pos==0 && tabmap[*ytab][*xtab-1]==1)// gauche //on verifie le positionement et que il ya bien un arbre
            {
                masked_blit(tabbit[13],tabbit[0],0,0,(*x-22),*y,tabbit[13]->w,tabbit[13]->h);//animation
                draw_sprite(screen,tabbit[0],0,0);//on affiche
                rest(200);
                masked_blit(tabbit[14],tabbit[0],0,0,(*x-22),*y,tabbit[14]->w,tabbit[14]->h);//case vide
                draw_sprite(screen,tabbit[0],0,0);//on affiche
                tabmap[*ytab][*xtab-1]=0;//on libére la case
                rest(200);
                xt=*x-22;//on enregistre les coordonées pixel et map ou l'arbre a été coupé
                yt=*y;
                ytt=*ytab;
                xtt=*xtab-1;
                i=1;// variable qui indique que un arbre a été coupé
            }
            if(*pos==1 && tabmap[*ytab-1][*xtab]==1)//haut
            {
                masked_blit(tabbit[13],tabbit[0],0,0,*x,(*y-22),tabbit[13]->w,tabbit[13]->h);
                draw_sprite(screen,tabbit[0],0,0);
                rest(200);
                masked_blit(tabbit[14],tabbit[0],0,0,*x,(*y-22),tabbit[14]->w,tabbit[14]->h);
                draw_sprite(screen,tabbit[0],0,0);
                tabmap[*ytab-1][*xtab]=0;
                rest(200);
                xt=*x;
                yt=*y-22;
                ytt=*ytab-1;
                xtt=*xtab;
                i=1;
            }
            if(*pos==2 && tabmap[*ytab][*xtab+1]==1)//droit
            {
                masked_blit(tabbit[13],tabbit[0],0,0,(*x+22),*y,tabbit[13]->w,tabbit[13]->h);
                draw_sprite(screen,tabbit[0],0,0);
                rest(200);
                masked_blit(tabbit[14],tabbit[0],0,0,(*x+22),*y,tabbit[14]->w,tabbit[14]->h);
                draw_sprite(screen,tabbit[0],0,0);
                tabmap[*ytab][*xtab+1]=0;
                rest(200);
                xt=*x+22;
                yt=*y;
                ytt=*ytab;
                xtt=*xtab+1;
                i=1;
            }
            if(*pos==-1 && tabmap[*ytab+1][*xtab]==1)//bas
            {
                masked_blit(tabbit[13],tabbit[0],0,0,*x,(*y+22),tabbit[13]->w,tabbit[13]->h);
                draw_sprite(screen,tabbit[0],0,0);
                rest(200);
                masked_blit(tabbit[14],tabbit[0],0,0,*x,(*y+22),tabbit[14]->w,tabbit[14]->h);
                draw_sprite(screen,tabbit[0],0,0);
                tabmap[*ytab+1][*xtab]=0;
                rest(200);
                xt=*x;
                yt=*y+22;
                ytt=*ytab+1;
                xtt=*xtab;
                i=1;
            }
        }
        k=0;
        if(*pos==2 && v==0 && ((*xtab+1)<20))//mouvement a droite
        {

            *xtab=*xtab+1;//on modifie les coordoné map du personnage
            for(p=0; p<11; p++)//boucle pour avoir un mouvement fluide
            {
                *x=*x+2;//legere augmentation
                masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);//carte
                if(n==3)

                {
                    masked_blit(tabbit[g],tabbit[0],0,0,xb,yb,tabbit[g]->w,tabbit[g]->h);//on affiche bien le bote si il y en a un
                }
                masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);//fruit
                if(i==1)//indique si l'arbre a été couper au mouvement d'avant
                {
                    masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);//case vide
                    tabmap[ytt][xtt]=1;//on reblinde la case ou l'arbe a été coupé au tour d'avance
                    if(p==10)
                    {
                        i=2;//indique que au prochain mouvement il faudra aussi affiché une case vide
                        k=1;

                    }
                }
                if(i==2 && k==0)//indique si un arbre a été couper deux mouvement plus tot
                {
                    masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);//case vide
                    if(p==10)
                    {
                        i=0;//remise a 0
                    }
                }
                masked_blit(tabbit[8],tabbit[0],0,0,*x,*y,tabbit[8]->w,tabbit[8]->h);//perso
                draw_sprite(screen,tabbit[0],0,0);//affichage
                rest(20);
            }

        }
        if(*pos==-1 && v==0 && ((*ytab+1)<20))//bas
        {
            *ytab=*ytab+1;
            for(p=0; p<11; p++)
            {
                *y=*y+2;
                masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
                if(n==3)

                {
                    masked_blit(tabbit[g],tabbit[0],0,0,xb,yb,tabbit[g]->w,tabbit[g]->h);
                }
                masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
                if(i==1)
                {
                    masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);
                    tabmap[ytt][xtt]=1;
                    if(p==10)
                    {
                        i=2;
                        k=1;

                    }
                }
                if(i==2 && k==0)
                {
                    masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);
                    if(p==10)
                    {
                        i=0;
                    }
                }
                masked_blit(tabbit[9],tabbit[0],0,0,*x,*y,tabbit[9]->w,tabbit[9]->h);
                draw_sprite(screen,tabbit[0],0,0);
                rest(20);
            }

        }
        if(*pos==0 && v==0 && ((*xtab-1)>-1))//gauche
        {
            *xtab=*xtab-1;
            for(p=0; p<11; p++)
            {
                *x=*x-2;
                masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
                if(n==3)

                {
                    masked_blit(tabbit[g],tabbit[0],0,0,xb,yb,tabbit[g]->w,tabbit[g]->h);
                }
                masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
                if(i==1)
                {
                    masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);
                    tabmap[ytt][xtt]=1;
                    if(p==10)
                    {
                        i=2;
                        k=1;
                    }
                }
                if(i==2 && k==0)
                {
                    masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);
                    if(p==10)
                    {
                        i=0;
                    }
                }
                masked_blit(tabbit[2],tabbit[0],0,0,*x,*y,tabbit[2]->w,tabbit[2]->h);
                draw_sprite(screen,tabbit[0],0,0);
                rest(20);
            }

        }
        if(*pos==1 && v==0 && ((*ytab-1)>-1))//haut
        {
            *ytab=*ytab-1;
            for(p=0; p<11; p++)
            {
                *y=*y-2;
                masked_blit(tabbit[1],tabbit[0],0,0,0,0,tabbit[1]->w,tabbit[1]->h);
                if(n==3)

                {
                    masked_blit(tabbit[g],tabbit[0],0,0,xb,yb,tabbit[g]->w,tabbit[g]->h);
                }
                masked_blit(tabbit[11],tabbit[0],0,0,xf2,yf2,tabbit[11]->w,tabbit[11]->h);
                if(i==1)
                {
                    masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);
                    tabmap[ytt][xtt]=1;
                    if(p==10)
                    {
                        i=2;
                        k=1;
                    }
                }
                if(i==2 && k==0)
                {
                    masked_blit(tabbit[14],tabbit[0],0,0,xt,yt,tabbit[14]->w,tabbit[14]->h);
                    if(p==10)
                    {
                        i=0;
                    }
                }
                masked_blit(tabbit[10],tabbit[0],0,0,*x,*y,tabbit[10]->w,tabbit[10]->h);
                draw_sprite(screen,tabbit[0],0,0);
                rest(20);
            }


        }
        if(tab[j]==0)
        {
            for(j=0; j<10; j++)//remise a 0 du tableau de deplacement
            {
                tab[j]=0;
            }
            return 0;//on arrete la boucle si rein ne suis
        }
        if(*xtab==xf && *ytab==yf)//si les coordonnées map du perso et du fruit sont les meme
        {
            return 1;//alors on retourne 1
        }
    }
    for(j=0; j<10; j++)//remise a 0 du tableau de deplacement
    {
        tab[j]=0;
    }
    return 0;//on retourne 0 si l'bjectif n'a pas été atteind
}
