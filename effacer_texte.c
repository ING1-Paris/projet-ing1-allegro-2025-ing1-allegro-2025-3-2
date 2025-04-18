// Created by galti on 18/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
// Effacer la zone du texte en restaurant la partie du fond correspondant
char effacer_texte(BITMAP*background,char *texte){
    int couleur_effacee = makecol(0,0,0);// couleur noire
    int x = SCREEN_W/2; // abscisses de début du texte
    int y = SCREEN_H/2; // ordonnées du début du texte
    /* HAUTEUR DU TEXTE*/
    int hauteur_zone = text_height(font)+10;
    /* LARGEUR DU TEXTE*/
    int largeur_zone = text_length(font,texte);
    /* RECTANGLE NOIR COUVRANT LE TEXTE*/
    rectfill(screen, x-largeur_zone/2, y-hauteur_zone/2, x+largeur_zone/2, y+hauteur_zone/2+20, couleur_effacee);
    /* RESTAURATION DU FOND D'ECRAN*/
    blit(screen, background, x-largeur_zone/2, y-hauteur_zone/2, x-largeur_zone/2, y-hauteur_zone/2, largeur_zone, hauteur_zone);
    return 0;
}