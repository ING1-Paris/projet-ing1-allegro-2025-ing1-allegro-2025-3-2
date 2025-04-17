// Created by galti on 16/04/2025.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"

char charge_mdp(t_joueur *joueur)
{

    /* ENREGISTREMENT DU MOT DE PASSE*/

    FILE* AjoutMdp = fopen("./donnees_sauvegardees/mdp.txt", "a"); // Ouverture du fichier pseudos.txt en mode ajout
    if (AjoutMdp == NULL) { // Erreur d'ouverture de fichier
        printf("Erreur d'ouverture de fichier\n");
        exit(1);
    }
    fprintf(AjoutMdp, "%s", joueur->mdp);
    printf("Votre mot de passe \"%s\" a ete sauvegarde.\n", joueur->mdp);
    fclose(AjoutMdp);
    AjoutMdp = NULL;

    return 0;
}
