// Created by galti on 18/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
// Effacer la zone du texte en restaurant la partie du fond correspondant
char effacer_texte(t_joueur *joueur,BITMAP*background){
    int couleur_effacee = makecol(0,0,0);// couleur noire
    //Cela fait s'effacer le texte
    // On détermine la largeur du texte
    int largeur_zone = text_length(font, "") + 10;
    // On calcule la hauteur du texte
    int hauteur_zone = text_height(font)+10;
    //On restaure le fond d'écran de la zone effacée
    blit(background, screen, x, y, x, y, largeur_zone, hauteur_zone);
    for (int i=0;i<text_length(font,")");i++)
    { // On fixe une limite de caractères pour le pseudo
        while (!key[KEY_ENTER])
        {// On ne s'arrête que quand le joueur appuie sur la touche ENTER
            //Retourne la touche appuyée
            readkey();
            if ((readkey()>>8) >= KEY_A && (readkey()>>8) <= KEY_Z)
            { // si le scancode de la touche appuyée est entre A et Z
                //On l'ajoute à joueur->user[i]
                key[readkey()>>8] = joueur->user[i];
                //On l'affiche avec textout
                textout_centre_ex(screen,font,joueur->user,x,y,couleur_texte,-1);
                //On met à jour i
                i++;
            }
            else
            {
                //Quoi qu'il arrive, on met à jour i
                i++;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}