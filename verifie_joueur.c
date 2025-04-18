// Created by galti on 17/04/2025.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"
char verifie_joueur(t_joueur *joueur, char name)
{
    /*DEFINITION DES VARIABLES*/
    char pseudos[NOMBRE_MAX_PSEUDOS][LONGUEUR_MAX_PSEUDO]; // Tableau de pseudos
    int i=0;

    /* OUVERTURE DU FICHIER EN MODE LECTURE*/
    FILE* Joueurs = fopen("./donnees_sauvegardees/joueur.txt", "r");
    if (Joueurs == NULL)
    { // Erreur d'ouverture de fichier
        printf("Erreur d'ouverture de fichier");
        exit(1);
    }
    while (fscanf(Joueurs, "%s %s", joueur->user,joueur->mdp) != EOF) {
        // Tant que la liste n'est pas finie, on compare le pseudo & le mdp donné avec la liste
        if (joueur->user == pseudos[i] && joueur->mdp == pseudos[i])
        {
            //Le pseudo & son mot de passe associé font partie de la liste des pseudos enregistrés
            return 0;
        }
        else
        {
            i++;
        }
    }
    fclose(Joueurs);
    Joueurs = NULL;
    if (name[5] == "user")
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

    if (name[5] == "mdp")
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