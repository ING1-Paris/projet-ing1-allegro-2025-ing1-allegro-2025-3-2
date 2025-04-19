// Created by galti on 16/04/2025.

#include <stdio.h>
#include <stdlib.h>
#include "signin.h"

char charge_joueur(t_joueur *joueur)
{
  FILE* AjoutJoueur = fopen("C:\\HORTENSE GALTIER\\2024-2025 ING1 ECE\\INFORMATIQUE\\PROJET INFO 2\\joueur.txt", "a"); // Ouverture du fichier pseudos.txt en mode ajout
  if (AjoutJoueur == NULL) { // Erreur d'ouverture de fichier
    printf("Erreur d'ouverture de fichier\n");
    exit(1);
  }
  fprintf(AjoutJoueur, "%s %s", joueur->user,joueur->mdp);
  fclose(AjoutJoueur);
  AjoutJoueur = NULL;
  return 0;
}
