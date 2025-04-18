// Created by galti on 18/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
// Effacer la zone du texte en restaurant la partie du fond correspondant
char effacer_texte(BITMAP*background,char *texte){
    int couleur_effacee = makecol(0,0,0);// couleur noire
    /* HAUTEUR DU TEXTE*/
    int hauteur_zone = text_height(font)+10;
    /* LARGEUR DU TEXTE*/
    int largeur_zone = text_length(font,texte);
    /* RECTANGLE NOIR COUVRANT LE TEXTE*/
    rectfill(background, x, y, x+largeur_zone, y+hauteur_zone, couleur_effacee);
    /* RESTAURATION DU FOND D'ECRAN*/
    blit(background, screen, x, y, x, y, largeur_zone, hauteur_zone);
    return 0;
}