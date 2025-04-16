
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
// Pour l'instant, le signin fonctionne sur la console
//Je dois encore le modifier pour que tout s'affiche sur la fenêtre du jeu
int signin(t_joueur *joueur)
{
    // PSEUDO
    printf("Choisissez un pseudo:\n");
    scanf("%c", joueur->user);
    if (joueur->user < 1 || joueur->user > 20)
    {
        printf("pseudo invalide.\n");
    }
    //On vérifie si le pseudo existes déjà
    else
    {
        // Le pseudo n'existes pas
        if(joueur->user != '\0' && joueur->user != charge_pseudo(joueur))
        {
            charge_pseudo(joueur);
            printf("Votre pseudo est enregistre. Choisissez a present un mot de passe.\n");
            scanf("%c", joueur->mdp);
            if (joueur->mdp <1 || joueur->mdp >12)
            {
                printf("mot de passe invalide.\n");
            }
            else
            {
                charge_mdp(joueur);
                printf("Votre mot de passe a ete enregistre.\n");
            }
            //On redirige le joueur vers login
            login(joueur);
        }
        // Le pseudo existes déjà
        else
        {
            // On vérifie si le joueur a cliqué au mauvais endroit
            printf("Ce pseudo existes deja.\n");
            printf("Est-ce vous ?\n");
            if (key[KEY_ENTER] == 1)
            {
                //On redirige le joueur vers login
                login(joueur);
            }
            else
            {
                // Le joueur doit choisir un nouveau pseudo
                signin(joueur);
            }
        }
    }
    return 0;
}