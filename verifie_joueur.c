// Created by galti on 17/04/2025.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"
char verifie_joueur(t_joueur *joueur, char *name)
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

    if (name[5] == "user")
    {
        while (fscanf(Joueurs, "%s", joueur->user) != EOF)
        {
            //On vérifie si le pseudo du joueur existe
            if (ustrstr(Joueur,joueur->user) != NULL)
            {
                //le pseudo existes
            }
            else
            {
                //le pseudo n'existe pas
            }
        }
    }

    /* SAISIE DU MOT DE PASSE*/

    if (name[5] == "mdp")
    {
        while (fscanf(Joueurs, "%s", joueur->mdp) != EOF)
        {
            //On vérifie si le pseudo du joueur existe
            if (ustrstr(Joueur,joueur->user) != NULL)
            {
                //le pseudo existes
            }
            else
            {
                //le pseudo n'existe pas
            }
        }
    }
    fclose(Joueurs);
    Joueurs = NULL;
    return 0;
}