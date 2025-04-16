
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
// Pour l'instant, le signin fonctionne sur la console
//Je dois encore le modifier pour que tout s'affiche sur la fenêtre du jeu
int signin(t_joueur *joueur)
{
    /*DEFINITION DES VARIABLES*/
    int couleur_texte = makecol(255,255,255);
    int x = 250; // abscisses de début du texte
    int y = 250; // ordonnées du début du texte


    textprintf_ex(screen,font,x,y,couleur_texte,-1,"Choisissez un pseudo [1-20 caracteres]:\n");
    scanf("%s", joueur->user);
    if (strlen(joueur->user) < 1 || strlen(joueur->user) > 20)
    {
        textprintf_ex(screen,font,x,y,couleur_texte,-1,"pseudo invalide.\n");
        return 0;
    }
    //On vérifie si le pseudo existes déjà
    else
    {
        // Le pseudo n'existes pas
        if(strcmp(joueur->user,charge_pseudo(joueur)) !=0)
        {
            charge_pseudo(joueur);
            textprintf_ex(screen,font, x,y,couleur_texte,-1,"Votre pseudo est enregistre. Choisissez a present un mot de passe.[1-12 caracteres]\n");
            scanf("%s", joueur->mdp);
            if (strlen(joueur->mdp) <1 || strlen(joueur->mdp) >12)
            {
                textprintf_ex(screen, font,x,y,couleur_texte,-1,"mot de passe invalide.\n");
                return 0;
            }
            else
            {
                charge_mdp(joueur);
                textprintf_ex(screen,font,x,y,couleur_texte,-1,"Votre mot de passe a ete enregistre.\n");
            }
            //On redirige le joueur vers login
            login(joueur);
        }
        // Le pseudo existes déjà
        else
        {
            // On vérifie si le joueur a cliqué au mauvais endroit
            textprintf_ex(screen,font,x,y,couleur_texte,-1,"Ce pseudo existes deja. Est-ce vous ?\n");
            if (key[KEY_ENTER] == 1)
            {
                //On redirige le joueur vers login
                login(joueur);
            }
            else
            {
                // Le joueur doit choisir un nouveau pseudo
                return signin(joueur);
            }
        }
    }
    return 0;
}