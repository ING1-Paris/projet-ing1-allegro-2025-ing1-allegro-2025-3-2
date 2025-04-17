// Created by galti on 16/04/2025.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"


char verifie_pseudo(t_joueur *joueur)
{
  /*DEFINITION DES VARIABLES*/
  char pseudos[NOMBRE_MAX_PSEUDOS][LONGUEUR_MAX_PSEUDO]; // Tableau de pseudos
  int numero = 0;
  int comparer = 0;
  int i=0;

  /* OUVERTURE DU FICHIER EN MODE LECTURE*/
  FILE* Pseudos = fopen("./donnees_sauvegardees/joueur.txt", "r");
  if (Pseudos == NULL)
  { // Erreur d'ouverture de fichier
    printf("Erreur d'ouverture de fichier");
    exit(1);
  }
  while (fscanf(Pseudos, "%s %s", joueur->user,joueur->mdp) != EOF) {
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
  fclose(Pseudos);
  Pseudos = NULL;
  return 0;
}


char charge_joueur(t_joueur *joueur)
{
  FILE* AjoutJoueur = fopen("./donnees_sauvegardees/joueur.txt", "a"); // Ouverture du fichier pseudos.txt en mode ajout
  if (AjoutJoueur == NULL) { // Erreur d'ouverture de fichier
    printf("Erreur d'ouverture de fichier\n");
    exit(1);
  }
  fprintf(AjoutJoueur, "%s %s", joueur->user,joueur->mdp);
  fclose(AjoutJoueur);
  AjoutJoueur = NULL;
  return 0;
}
