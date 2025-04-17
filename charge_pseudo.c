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
  FILE* Pseudos = fopen("./donnees_sauvegardees/pseudos.txt", "r");
  if (Pseudos == NULL)
  { // Erreur d'ouverture de fichier
    printf("Erreur d'ouverture de fichier");
    exit(1);
  }
  /* COMPTABILISE LE NOMBRE DE PSEUDOS ENREGISTRES*/
  while (fscanf(Pseudos, "%s", pseudos[numero]) == 1)
  {
    numero++;
  }
  printf("%d",numero); // ligne de vérification dans la console

  /* VERIFICATION DE L'EXISTENCE DU PSEUDO*/
  for (i = 0; i <= numero; i++)
  { // On parcourt toutes les lignes
    comparer = strcmp(pseudos[i], joueur->user); // Comparaison entre pseudos[i] et joueur-> user
    if (comparer == 0)
    {
      i++; // On va à la ligne suivante
    }
    else // le pseudo ne fait pas partie de la liste des pseudos enregistrés
    {
      //On sort de la boucle for
      return 0;
    }
  }
  if (i==numero)
  {
    printf("Le pseudo n'existes pas encore.");
    return 1;
  }
  else
  {
    //On ferme le fichier
    fclose(Pseudos);
    Pseudos = NULL;
    return 0;
  }
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
