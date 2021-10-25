#ifndef BIBLIO2_H_INCLUDED
#define BIBLIO2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<allegro.h>
// prototypes
void lancerToutAllegro(int , int );
void remplirtabbit(BITMAP*tab[20]);
int menu();
int aide();
int compare(int);
void remplirtab(BITMAP* [20],int* ,int , int ,int);
int liretab(BITMAP*[20],int*,int(*)[20], int* ,int* ,int* ,int*,int* , int, int, int,int, int, int );
void jeu(BITMAP* [20], int(*)[20], int);
void remplirtabmap(BITMAP*[20], int(*)[20]);
int verif(int(*)[20],int* ,int*, int*);
int niv1(BITMAP* [20], int(*)[20]);
int position(int*,int);
void demitour(BITMAP* [20], int, int*,int, int, int*, int*, int,int,int,int);
int niv2(BITMAP* [20], int(*)[20]);
int choixniv();
int niv3(BITMAP* [20], int(*)[20]);
void remplirtabbotn3(BITMAP* [20], int*, int);
int liretabbot(BITMAP*[20],int*, int* ,int* ,int* ,int*,int* , int, int,int, int, int );
void demitourbot(BITMAP*[20], int*, int*, int*,int,int,int);
int debug(int ,int );
void remplirtabbotn4(BITMAP* [20], int*, int);
int niv4(BITMAP* [20], int(*)[20]);
#endif // BIBLIO2_H_INCLUDED
