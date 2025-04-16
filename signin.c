// Created by galti on 15/04/2025.
#include "signin.h"
#include <stdio.h>
int signin(t_joueur *joueur)
{
    // PSEUDO
    printf("Choisissez un pseudo:\n");
    scanf("%c", joueur->user);
    if (joueur->user < 1 || joueur->user > 20)
    {
        printf("Votre pseudo n'a pas le nombre de caracteres requis.\n");
    }
    //On vérifie si le pseudo existes déjà
    // Le pseudo n'existes pas
    if(joueur->user != '\0' && joueur->user != charge_pseudo(joueur))
    {
        printf("Votre pseudo est enregistre.\n");
        charge_pseudo(joueur);
        printf("Choisissez un mot de passe.\n");
        scanf("%c", joueur->mdp);
        if (joueur->mdp <1 && joueur->mdp >12)
        {
            printf("Votre mot de passe n'est pas valide.\n");
        }
        else
        {
            charge_mdp(joueur);
            printf("Votre mot de passe a ete enregistre.\n");
        }

    }
    // Le pseudo existes déjà
 return 0;
}
