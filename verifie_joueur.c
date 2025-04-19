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
            if (strcmp(fgets(joueur->user,1,Joueurs),joueur->user)== 0)
            {
                //le pseudo existes
                return true;
            }
            else
            {
                //le pseudo n'existe pas
                return false;
            }
        }
    }

    /* SAISIE DU MOT DE PASSE*/

    if (strcmp(name,"mdp") == 0) //Si le mot de passe existes, on vérifie s'il est bien associé au pseudo entré
    {
        while (fscanf(Joueurs, "%s", joueur->mdp) != EOF)
        {
            //On vérifie si le pseudo du joueur existe
            if (strcmp(fgets(joueur->mdp,1,Joueurs),joueur->mdp)== 0)
            {
                //le mot de passe  existes
                return true;
            }
            else
            {
                //le mot de passe n'existe pas
                return false;
            }
        }
    }
    fclose(Joueurs);
    Joueurs = NULL;
    return true; //par défaut, on retourne true
}