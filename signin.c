
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"

int signin(t_joueur *joueur,BITMAP*background)
{
    /*DEFINITION DES VARIABLES ALLEGRO*/
    int couleur_texte = makecol(255,255,255);// couleur blanche
    int x = SCREEN_W/2; // abscisses de début du texte
    int y = SCREEN_H/2; // ordonnées du début du texte

	/* CHOIX DU PSEUDO */

    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Choisissez un pseudo de 1-20 caracteres[ENTER]:\n");
    scanf("%s", joueur->user);

	/* VALIDATION DU PSEUDO*/
    if (keypressed() && key[KEY_ENTER] == 0)
    {
        // Le joueur n'a pas validé son choix : On le redirige vers le début du programme
        signin(joueur,background);
        return 0;
    }
    if(keypressed() && key[KEY_ENTER] == 1) // le joueur a validé son choix
    {
        // On efface le texte précédent
        effacer_texte(joueur,background);

        /* VERIFICATION DE LA TAILLE DU PSEUDO*/
        if (strlen(joueur->user) < 1 || strlen(joueur->user) > 20)
        {
            textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"pseudo invalide.\n");
            rest(10000); // 10 secondes
            // On efface le texte précédent
            effacer_texte(joueur,background);
            // On revient au début du programme
            signin(joueur,background);
            return 0;
        }
        // Le pseudo choisi est valide : On vérifie s'il est déjà utilisé ou non
        else {
            // Le pseudo existes déjà
            if(strcmp(joueur->user,verifie_pseudo) ==0) {
                textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Ce pseudo existes deja. Est-ce vous ?[ENTER]\n");
                if (keypressed() && key[KEY_ENTER] == 0)
                {
                    // Le joueur doit choisir un nouveau pseudo
                    signin(joueur,background);
                    return 0;
                }
                if (keypressed() && key[KEY_ENTER] == 1)
                {
                    // C'est lui : on le redirige vers le menu principal(->login)
                    return 0;
                }
            }
            else // Le pseudo n'existes pas
            {
                // On enregistres le pseudo
                charge_pseudo(joueur);
                textprintf_centre_ex(screen,font, x,y,couleur_texte,-1,"Votre pseudo est enregistre. Choisissez a present un mot de passe a 1-12 caracteres[ENTER]\n");
                scanf("%s", joueur->mdp);
                /* VALIDATION DU MOT DE PASSE*/
                if (keypressed() && key[KEY_ENTER] == 0)
                {
                    // Le joueur n'a pas validé son choix : on le rediriges vers le début du programme
                    signin(joueur,background);
                }
                if (keypressed() && key[KEY_ENTER] == 1)
                {
                    /* VERIFICATION DE LA TAILLE DU MOT DE PASSE */
                    if (strlen(joueur->mdp) <1 || strlen(joueur->mdp) >12)
                    {
                        textprintf_centre_ex(screen, font,x,y,couleur_texte,-1,"mot de passe invalide.\n");
                        rest(10000); // 10 secondes
                        // On efface le texte précédent
                        effacer_texte(joueur,background);
                        // On retourne au début du programme
                        signin(joueur,background);
                        return 0;
                    }
                    else
                    {
                        charge_mdp(joueur);
                        textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Votre mot de passe a ete enregistre.\n");
                        rest(10000); // 10 secondes
                        // On efface le texte
                        effacer_texte(joueur,background);
                        // On retourne au menu principal (-> login)
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}