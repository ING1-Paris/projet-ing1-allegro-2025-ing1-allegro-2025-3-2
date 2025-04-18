
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"

int signin(t_joueur *joueur,BITMAP*background)
{
    /*DEFINITION DES VARIABLES ALLEGRO*/
    int couleur_texte = makecol(255,255,255);// couleur blanche
    int x = SCREEN_W/2; // abscisses du texte
    int y = SCREEN_H/2; // ordonnées du texte
    char name[5]; // indicateur de saisie

    /* CHOIX ET VALIDATION DU PSEUDO*/
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Choisissez un pseudo de 1-20 caracteres[ENTER]:\n");
    name[5] = "user";
    *joueur->user == ecrire_texte(joueur,name); //Equivalent du scanf mais en allegro : saisie du pseudo
    switch (readkey() >> 8)
    {
        effacer_texte(background,texte); //on efface la question
        effacer_texte(background,texte);// On efface le pseudo
        case KEY_ENTER: // Le joueur a validé son choix
        {
            if(verifie_joueur) // fonction vérifiant l'existence du pseudo
            {
                textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Ce pseudo existes deja. Est-ce vous ?[ENTER]\n");
                rest(10000); // 10 secondes
                effacer_texte(background,texte);// On efface la question
                switch (readkey()>> 8)
                {
                    case KEY_ENTER:
                    {
                        //C'est bien lui : on le rediriges vers la page d'accueil
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
                //Le pseudo n'existes pas : on peut sortir de la boucle pour choisir le mdp
                return 0;
            }
            break;
        }
        default:
        {
            //le joueur n'as pas validé son choix
            signin(joueur, background);
            break;
        }
    }

    /* CHOIX ET VALIDATION DU MOT DE PASSE */

    textprintf_centre_ex(screen,font, x,y,couleur_texte,-1,"Choisissez a present un mot de passe a 1-12 caracteres[ENTER]\n");
    // On saisit le mot de passe
    char name[5] = "mdp";
    // équivalent du scanf mais en allegro
    *joueur->mdp == ecrire_texte(joueur,name); // saisie du mot de passe
    switch (readkey() >> 8)
    {
        effacer_texte(background,texte);// On efface la question
        effacer_texte(background,texte);// On efface le mot de passe
        case KEY_ENTER:
        {
            charge_joueur(joueur);//On peut enregistrer le pseudo & le mot de passe
            textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"signin reussi !.\n");
            rest(10000); // 10 secondes
            effacer_texte(background,texte);
            // On revient au menu principal
            break;
        }
        default:
        {
            // Le joueur n'a pas validé son choix : on le rediriges vers le début du programme
            signin(joueur,background);
            break;
        }
    }
    return 0;
}