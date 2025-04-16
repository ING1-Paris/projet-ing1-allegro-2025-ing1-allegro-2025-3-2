//
// Created by galti on 16/04/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signin.h"
int charge_pseudo(t_joueur *joueur){
  /*ON VERIFIE SI LE PSEUDO EXISTES*/
  /*DEFINITION DES VARIABLES*/
  char pseudos[NOMBRE_MAX_PSEUDOS][LONGUEUR_MAX_PSEUDO]; // Tableau de pseudos
  int numero = 0;
  int test = 0;

  // On lit les pseudos
  FILE* Pseudos = fopen("./donnees_sauvegardees/pseudos.txt", "r"); // Ouverture du fichier pseudos.txt en mode lecture
  if (Pseudos == NULL) { // Erreur d'ouverture de fichier
    printf("Erreur d'ouverture de fichier");
    exit(1);
  }
  while (fscanf(Pseudos, "%s", pseudos[numero]) == 1){
    numero++;
  }
  fclose(Pseudos);
  Pseudos = NULL;

  // On vérifie si le pseudo entré existe déjà
  for (int i = 0; i <= numero; i++) { // On parcourt toutes les lignes
    test = strcmp(pseudos[i], &joueur->user); // Comparaison entre pseudo_lus[i] et pseudo
    if (test == 0) { // Dans le cas où pseudo_lus[i] = pseudo
      printf("Erreur : Le pseudo que vous avez saisi : \"%s\" existe deja.\n", &joueur->user);
      exit(1);
    }
  }
  // Situation où le pseudo n'existe pas déjà :
  // 1) on ajoute le pseudo dans pseudos.txt
  // (dans pFichierPseudosA, le A est pour "Add")
  FILE* pFichierPseudosA = fopen("./donnees_sauvegardees/pseudos.txt", "a"); // Ouverture du fichier pseudos.txt en mode ajout
  if (pFichierPseudosA == NULL) { // Erreur d'ouverture de fichier
    printf("Erreur d'ouverture de fichier\n");
    exit(1);
  }
  fprintf(pFichierPseudosA, "%s", &joueur->user);
  fprintf(pFichierPseudosA, "%s", "\n");
  printf("Votre pseudo \"%s\" a ete sauvegarde.\n", &joueur->user);
  fclose(pFichierPseudosA);
  pFichierPseudosA = NULL;
  // 2) Enregistrement de 0 à la ligne correspondant au joueur dans scores.txt
  FILE* pFichierScoreA = fopen("./donnees_sauvegardees/scores.txt", "a");
  if (pFichierScoreA == NULL) { // Erreur d'ouverture de fichier
    printf("Erreur d'ouverture de fichier");
    exit(1);
  }
  fprintf(pFichierScoreA, "%d", 0);
  fprintf(pFichierScoreA, "%s", "\n");
  fclose(pFichierScoreA);
  pFichierScoreA = NULL;
  //Si oui, on ne fait rien
  // Si non, on l'ajoutes à la liste des pseudos

  return 0;
}