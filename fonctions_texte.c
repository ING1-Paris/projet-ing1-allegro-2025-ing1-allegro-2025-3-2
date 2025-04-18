//
// Created by galti on 17/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
// Effacer la zone du texte en restaurant la partie du fond correspondant
void effacer_texte(t_joueur *joueur,BITMAP*background){
    int couleur_effacee = makecol(0,0,0);// couleur noire
    //Cela fait s'effacer le texte
    // On détermine la largeur du texte
    int largeur_zone = text_length(font, "") + 10;
    // On calcule la hauteur du texte
    int hauteur_zone = text_height(font)+10;
    //On restaure le fond d'écran de la zone effacée
    blit(background, screen, x, y, x, y, largeur_zone, hauteur_zone);

}
// saisie + affichage du texte au fur et à mesure de la saisie
// respecte la limite de caractères : entre 1 et 12-> mdp et entre 1 et 20 -> pseudo
//1) Boucle while qui lit avec readkey()
//2) Construit la chaîne caractère par caractère
//3) Affiche la chaîne en direct avec textout à chaque itération
//4) Enregistre le pseudo final dans joueur->user et le mdp final dans joueur->mdp
void ecrire_texte(t_joueur *joueur) {
    while (!key[KEY_ENTER]) {

    }
}