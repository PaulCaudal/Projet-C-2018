#include"biblio2.h"
#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>

void lancerToutAllegro(int largeur, int hauteur)
{
    /// initialisation générale
    allegro_init();
    /// pour utiliser le clavier
    install_keyboard();
    /// pour utiliser la souris
    install_mouse();
    /// initialisation du MODE GRAPHIQUE
    //on fixe le mode couleur (8, 16, 24 ou 32 bits)
    set_color_depth(desktop_color_depth());
    // on essaie d’ouvrir une fenêtre de largeur*hauteur pixels
    // si l’ouverture échoue on quitte
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,largeur,hauteur,0,0)!=0)
    {
        allegro_message("probleme mode graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    /// si on veut afficher le pointeur de souris
    show_mouse(screen);
}

void remplirtabbit(BITMAP*tab[20])// sous programme qui remplie le tableau de bitmap
{
    int i;
    tab[1]=load_bitmap("carte.bmp",NULL);// ouverture de toute les bitmap
    tab[4]=load_bitmap("droit.bmp",NULL);
    tab[5]=load_bitmap("quitter.bmp",NULL);
    tab[6]=load_bitmap("gauche.bmp",NULL);
    tab[7]=load_bitmap("haut.bmp",NULL);
    tab[3]=load_bitmap("boutons.bmp",NULL);
    tab[2]=load_bitmap("persogauche.bmp",NULL);
    tab[8]=load_bitmap("persodroit.bmp",NULL);
    tab[9]=load_bitmap("persobas.bmp",NULL);
    tab[10]=load_bitmap("persohaut.bmp",NULL);
    tab[11]=load_bitmap("fruit.bmp",NULL);
    tab[12]=load_bitmap("hache.bmp",NULL);
    tab[13]=load_bitmap("nuage.bmp",NULL);
    tab[14]=load_bitmap("new.bmp",NULL);
    tab[15]=load_bitmap("suppr.bmp",NULL);
    tab[16]=load_bitmap("botgauche.bmp",NULL);
    tab[17]=load_bitmap("botdroit.bmp",NULL);
    tab[18]=load_bitmap("botbas.bmp",NULL);
    tab[19]=load_bitmap("bothaut.bmp",NULL);
    tab[0]=create_bitmap(SCREEN_W,SCREEN_H);// creation d'un buffer
    // blidage
    for(i=0; i<20; i++)
    {

        if(!tab[i])
        {
            allegro_message("pas pu trouver/ charger earth.bmp");
            allegro_exit();
            exit(EXIT_FAILURE);
        }
    }


}
int menu()// sous programme du menu
{
    BITMAP*menu;//declaration bitmap
    BITMAP*buff;
    menu=load_bitmap("menu.bmp",NULL);// ouverture bitmap
    buff=create_bitmap(SCREEN_W,SCREEN_H);//creation d'un buffer
    if(!menu)
    {
        allegro_message("pas pu trouver/ charger earth.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    int i=0;// variable prenant la valeur 1, 2 ou 3 en fonction du choix
    int x, y;// variable pour enregistré des coordoné
    x=0;// initalisation de ces variable
    y=0;
    int j=makecol(63,72,204);// declaration des 4 variable correspondant a 4 couleurs //jouer
    int n=makecol(255,242,0);//niveau
    int a=makecol(34,177,76);//aide
    int q=makecol(237,28,36);//quitter
    int r;// variable pour le getpixel
    r=makecol(0,0,0);//initialisation de cet variable
    masked_blit(menu,buff,0,0,0,0,menu->w,menu->h);// copie de menu sur le buffer
    draw_sprite(screen,buff,0,0);// dessine le buffer sur screen
    while(i==0)
    {

        if(mouse_b &1)// detection du clic gauche
        {
            x=mouse_x;//enregistrement des coordonées
            y=mouse_y;
            mouse_b=0;
        }
        r=getpixel(buff,x,y);// getpixel a l'endroit du clic
        if(r==j)// on compare avec nos valeur et i prend une valeur en fonction de la couleur détecter
        {
            i=1;
        }
        if(r==a)
        {
            i=2;
        }
        if(r==q)
        {
            i=3;
        }
        if(r==n)
        {
            i=4;
        }
    }
    clear_to_color(screen,makecol(0,0,0));
    clear_to_color(buff,makecol(0,0,0));
    return i;// on retourne i
}

int compare(int r)//sous programme qui compare la couleur du clic avec des couleur qui ont un sens pour nous
{
    int v=makecol(255,0,0);//bouton validation
    int d=makecol(255,255,255);//quart de tour droit
    int q=makecol(163,73,164);//quitter
    int g=makecol(255,254,255);//quart de tour gauche
    int a=makecol(255,255,254);//avancé
    int s=makecol(255,1,0);
    int i;
    if (r==d)// en fonction de la correspondance i prend une valeur
    {
        i=1;
    }
    if (r==g)
    {
        i=2;
    }
    if (r==a)
    {
        i=3;
    }
    if (r==v)
    {
        i=0;
    }
    if(r==q)
    {
        i=5;
    }
    if(r==s)
    {
        i=6;
    }
    return i;//on retourne i
}

int choixniv()
{
    BITMAP*niveau;
    BITMAP*buff;
    niveau=load_bitmap("niveau.bmp",NULL);// ouverture bitmap
    buff=create_bitmap(SCREEN_W,SCREEN_H);//creation d'un buffer
    if(!niveau)
    {
        allegro_message("pas pu trouver/ charger earth.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    int n1=makecol(63,72,204);
    int n2=makecol(255,242,0);
    int n3=makecol(34,177,76);
    int n4=makecol(237,28,36);
    int i=0;// variable prenant la valeur 1, 2 ou 3 en fonction du choix
    int r;
    int x, y;// variable pour enregistré des coordoné
    x=0;// initalisation de ces variable
    y=0;
    while(i==0)
    {
        masked_blit(niveau,buff,0,0,0,0,niveau->w,niveau->h);// copie de menu sur le buffer
        draw_sprite(screen,buff,0,0);// dessine le buffer sur screen
        if(mouse_b &1)// detection du clic gauche
        {
            x=mouse_x;//enregistrement des coordonées
            y=mouse_y;
            mouse_b=0;
        }
        r=getpixel(buff,x,y);// getpixel a l'endroit du clic
        if(r==n1)// on compare avec nos valeur et i prend une valeur en fonction de la couleur détecter
        {
            i=1;
        }
        if(r==n2)
        {
            i=2;
        }
        if(r==n3)
        {
            i=3;
        }
        if(r==n4)
        {
            i=4;
        }
    }
    clear_to_color(screen,makecol(0,0,0));
    clear_to_color(buff,makecol(0,0,0));
    return i;// on retourne i

}
int aide()
{
        BITMAP*aide;
    BITMAP*buff;
    aide=load_bitmap("aide.bmp",NULL);// ouverture bitmap
    buff=create_bitmap(SCREEN_W,SCREEN_H);//creation d'un buffer
    if(!aide)
    {
        allegro_message("pas pu trouver/ charger earth.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    int c=makecol(163,73,164);
    int r=0;
    int x=0;
    int y=0;
    while(r!=c)
    {
        masked_blit(aide,buff,0,0,0,0,aide->w,aide->h);// copie de menu sur le buffer
        draw_sprite(screen,buff,0,0);// dessine le buffer sur screen
        if(mouse_b &1)// detection du clic gauche
        {
            x=mouse_x;//enregistrement des coordonées
            y=mouse_y;
            mouse_b=0;
        }
        r=getpixel(buff,x,y);
    }
    return 0;
}
