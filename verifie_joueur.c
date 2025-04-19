// Created by galti on 17/04/2025.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"
bool verifie_joueur(t_joueur *joueur, char *name)
{

    /* OUVERTURE DU FICHIER EN MODE LECTURE*/
    FILE* Joueurs = fopen("./donnees_sauvegardees/joueur.txt", "r");
    if (Joueurs == NULL)
    { // Erreur d'ouverture de fichier
        printf("Erreur d'ouverture de fichier");
        exit(1);
    }

    if (strcmp(name,"user") == 0)
    {
        while (fscanf(Joueurs, "%s", joueur->user) != EOF)
        {
            //On vérifie si le pseudo du joueur existe
            if (strstr(Joueurs,joueur->user) != NULL)
            {
                //le pseudo existes
                return true; // On renvoie true si le pseudo existe
            }
            else
            {
                //le pseudo n'existe pas
                return false; // On renvoie false si le pseudo n'existe pas
            }
        }
    }

    /* SAISIE DU MOT DE PASSE*/

    if (strcmp(name,"mdp") == 0)
    {
        while (fscanf(Joueurs, "%s", joueur->mdp) != EOF)
        {
            //On vérifie si le pseudo du joueur existe
            if (strstr(Joueurs,joueur->user) != NULL)
            {
                //le pseudo existes
                return true; // On renvoie true si le pseudo existe
            }
            else
            {
                //le pseudo n'existe pas
                return false; // On renvoie false si le pseudo n'existe pas
            }
        }
    }
    fclose(Joueurs);
    Joueurs = NULL;
    return 0;
}