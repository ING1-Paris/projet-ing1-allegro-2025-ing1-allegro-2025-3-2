//
// Created by galti on 17/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
// Effacer la zone du texte en restaurant la partie du fond correspondant
void effacer_texte(t_joueur *joueur,BITMAP*background){

    //Le joueur doit appuyer sur "enter" pour valider son choix
    if(key[KEY_ENTER] == 1)
    {
        //Cela fait s'effacer le texte
        // On détermine la largeur du texte
        int largeur_zone = text_length(font, "") + 10;
        // On calcule la hauteur du texte
        int hauteur_zone = text_height(font);
        //On restaure le fond d'écran de la zone effacée
        blit(background, screen, x, y, x, y, largeur_zone, hauteur_zone);
        return 0;
    }
    else
    {
        //Le joueur a appuyé sur une mauvaise touche/n'a pas appuyé du tout
        //On le redirige ves le début de la fonction
        signin(joueur,background);
    }
}