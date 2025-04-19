// Created by galti on 17/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"


char ecrire_texte(t_joueur *joueur,char *name) {
    /*DEFINITION DES VARIABLES*/
    int couleur_texte = makecol(255,255,255);
    int x = SCREEN_W/2; // abscisses de début du texte
    int y = SCREEN_H/2; // ordonnées du début du texte

    /* SAISIE DU PSEUDO*/

    if (strcmp(name,"user") == 0)
    {
        for (int i=0;i<20;i++)
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
                    textout_centre_ex(screen,font,joueur->user,x,y+20,couleur_texte,-1);
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
        return joueur->user;
    }

    /* SAISIE DU MOT DE PASSE*/

    if (strcpy(name,"mdp") == 0)
    {
        for (int i=0;i<12;i++)
        { // On fixe une limite de caractères pour le mot de passe
            while (!key[KEY_ENTER])
            {// On ne s'arrête que quand le joueur appuie sur la touche ENTER
                //Retourne la touche appuyée
                readkey();
                if ((readkey()>>8) >= KEY_A && (readkey()>>8) <= KEY_Z)
                { // si le scancode de la touche appuyée est entre A et Z
                    //On l'ajoute à joueur->user[i]
                    key[readkey()>>8] = joueur->mdp[i];
                    //On l'affiche avec textout
                    textout_centre_ex(screen,font,joueur->mdp,x,y+20,couleur_texte,-1);
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
        return joueur->mdp;
    }
    return 0;
}