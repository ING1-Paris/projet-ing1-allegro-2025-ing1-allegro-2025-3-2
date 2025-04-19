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
        for (int i=0;i<20;i++) {
            printf("test1\n");
            readkey();//Retourne la touche appuyée
            printf("test2\n");
            if ((readkey()>>8) >= KEY_A && (readkey()>>8) <= KEY_Z)
            { // si le scancode de la touche appuyée est entre A et Z : on l'ajoute à joueur->user[i]
                joueur->user[i] = key[readkey()>>8]; // PROBLEME DANS LA LECTURE DE LA TOUCHE
                printf("test4\n");
                printf("%c\n",joueur->user[i]);
                //On l'affiche avec textout
                textout_centre_ex(screen,font,joueur->user,x,y+20,couleur_texte,1);
            }
            if (key[KEY_ENTER])
            {
                return joueur->user;
            }
        }
        /*for (int i=0;i<20;i++)
        { // On fixe une limite de caractères pour le pseudo
            printf("limite de caracteres\n");
            while (!key[KEY_ENTER])
            {// On ne s'arrête que quand le joueur appuie sur la touche ENTER
                printf("test\n");
                readkey();//Retourne la touche appuyée
                printf("test2\n");
                if ((readkey()>>8) >= KEY_A && (readkey()>>8) <= KEY_Z)
                { // si le scancode de la touche appuyée est entre A et Z : on l'ajoute à joueur->user[i]
                    joueur->user[i] = key[readkey()>>8];
                    //On l'affiche avec textout
                    textout_centre_ex(screen,font,joueur->user,x,y+20,couleur_texte,-1);
                }
            }
        }*/
        textout_centre_ex(screen,font,joueur->user,x,y+20,couleur_texte,-1); // On affiche tout le pseudo
        return joueur->user;
    }

    /* SAISIE DU MOT DE PASSE*/

    if (strcmp(name,"mdp") == 0)
    {
        for (int i=0;i<12;i++)
        { // On fixe une limite de caractères pour le mot de passe
            while (!key[KEY_ENTER])
            {// On ne s'arrête que quand le joueur appuie sur la touche ENTER
                readkey();//Retourne la touche appuyée
                if ((readkey()>>8) >= KEY_A && (readkey()>>8) <= KEY_Z)
                { // si le scancode de la touche appuyée est entre A et Z : on l'ajoute à joueur->user[i]
                    joueur->mdp[i] = key[readkey()>>8];
                    //On l'affiche avec textout
                    textout_centre_ex(screen,font,joueur->mdp,x,y+20,couleur_texte,-1);
                }
            }
        }
        textout_centre_ex(screen,font,joueur->mdp,x,y+20,couleur_texte,-1); // On affiche tout le mot de passe
        return joueur->mdp;
    }
    if (strcmp(name,"user") != 0 && strcmp(name,"mdp") != 0)
    {
        return 1;
    }
    return 0;
}