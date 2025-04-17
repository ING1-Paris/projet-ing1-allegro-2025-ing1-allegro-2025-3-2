
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
/* FAIRE UN FICHIER COMMUN POUR USER ET MDP !!!*/
int signin(t_joueur *joueur,BITMAP*background)
{
    /*DEFINITION DES VARIABLES ALLEGRO*/
    int couleur_texte = makecol(255,255,255);// couleur blanche
    int x = SCREEN_W/2; // abscisses de début du texte
    int y = SCREEN_H/2; // ordonnées du début du texte

	/* CHOIX DU PSEUDO */

    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Choisissez un pseudo de 1-20 caracteres[ENTER]:\n");
    scanf("%s", joueur->user);
    switch (readkey() >> 8)
    {
        /* VALIDATION DU PSEUDO*/
        case KEY_ENTER:
        {
            // Le joueur a validé son choix
            // On efface le texte précédent
            effacer_texte(joueur,background);
            //On vérifie la taille du pseudo
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
            // le pseudo est valide : on vérifie s'il est déjà utilisé
            else
            {
                // Le pseudo existes déjà
                if(strcmp(joueur->user,verifie_pseudo) ==0) {
                    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Ce pseudo existes deja. Est-ce vous ?[ENTER]\n");
                    switch (readkey()>> 8)
                    {
                        case KEY_ENTER:
                        {
                            //C'est bien lui : on le rediriges vers le menu principal
                            break;
                        }
                        default:
                        {
                            // Le joueur doit choisir un nouveau pseudo
                            signin(joueur,background);
                            break;
                        }
                    }
                }
                else
                {
                    //Le pseudo n'existes pas : on peut à présent choisir un mot de passe
                    textprintf_centre_ex(screen,font, x,y,couleur_texte,-1,"Choisissez a present un mot de passe a 1-12 caracteres[ENTER]\n");
                    scanf("%s", joueur->mdp);
                    /* VALIDATION DU MOT DE PASSE*/
                    switch (readkey() >> 8)
                    {
                        case KEY_ENTER: {
                            /* VERIFICATION DE LA TAILLE DU MOT DE PASSE*/
                            if (strlen(joueur->mdp) < 1 || strlen(joueur->mdp) > 12) {
                                textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"mot de passe invalide.\n");
                                rest(10000); // 10 secondes
                                // On efface le texte précédent
                                effacer_texte(joueur,background);
                                // On revient au début du programme
                                signin(joueur,background);
                                return 0;
                            }
                            else {
                                //On peut enregistrer le pseudo & le mot de passe
                                charger_joueur(joueur);
                                textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"signin reussi !.\n");
                                rest(10000); // 10 secondes
                                effacer_texte(joueur,background);
                                // On revient au menu principal
                                return 0;
                            }
                            break;
                        }
                        default: {
                            // Le joueur n'a pas validé son choix : on le rediriges vers le début du programme
                            signin(joueur,background);
                            break;
                        }
                    }
                }
            }
            break;
        }
            default:
        {
            //le joueur n'a pas validé son choix
            signin(joueur,background);
            break;
        }
    }
    return 0;
}