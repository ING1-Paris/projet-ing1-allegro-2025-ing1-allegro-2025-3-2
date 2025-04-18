// Created by galti on 17/04/2025.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"
char verifie_joueur(t_joueur *joueur)
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
    return 0;
}