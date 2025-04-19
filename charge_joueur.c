// Created by galti on 16/04/2025.

#include <stdio.h>
#include <stdlib.h>
#include "signin.h"

char charge_joueur(t_joueur *joueur)
{
  FILE* AjoutJoueur = fopen("C:\\Users\\galti\\CLionProjects\\ece type\\joueur.txt", "a"); // Ouverture du fichier joueur.txt en mode ajout
  if (AjoutJoueur == NULL) { // Erreur d'ouverture de fichier
    printf("Erreur d'ouverture de fichier\n");
    exit(1);
  }
  fprintf(AjoutJoueur, "%s %s", joueur->user,joueur->mdp);
  fclose(AjoutJoueur);
  AjoutJoueur = NULL;
  return 0;
}
