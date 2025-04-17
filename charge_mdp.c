// Created by galti on 16/04/2025.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"

char charge_mdp(t_joueur *joueur)
{

    /* ENREGISTREMENT DU PSEUDO*/

    FILE* AjoutPseudo = fopen("./donnees_sauvegardees/pseudos.txt", "a"); // Ouverture du fichier pseudos.txt en mode ajout
    if (AjoutPseudo == NULL) { // Erreur d'ouverture de fichier
        printf("Erreur d'ouverture de fichier\n");
        exit(1);
    }
    fprintf(AjoutPseudo, "%s", joueur->user);
    printf("Votre pseudo \"%s\" a ete sauvegarde.\n", joueur->user);
    fclose(AjoutPseudo);
    AjoutPseudo = NULL;

    return 0;
}
