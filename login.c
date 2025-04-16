
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
int login(t_joueur *joueur)
{
  /*DEFINITION DES VARIABLES*/
  int essai =0;

  for(essai=0;essai<3;essai++)
  {
    printf("Saisissez votre nom d'utilisateur:\n");
    scanf("%s", joueur->user);
    if(strcmp(joueur->user,lecture_pseudo(joueur))==0)
    {
      //Pseudo invalide
      printf("Votre nom d'utilisateur n'existes pas.\n");
      essai = essai - 1;
    }
    else
    {
      printf("Vous pouvez saisir votre mot de passe.\n");
      printf("Saisissez votre mot de passe:\n");
      scanf("%c", joueur->mdp);
      for(essai=0;essai<3;essai++)
      {
        if(strcmp(joueur->user,lecture_mdp(joueur))==0)
        {
          printf("Votre mot de passe est invalide.\n");
          essai = essai - 1;
        }
        else
        {
          printf("connexion reussie.\n");
          // renvoie vers page de jeu (niveaux)
        }
      }
      printf("Vous n'avez plus d'essais disponibles.\n");
      return 0;
    }
  }
  printf("Vous n'avez plus d'essais disponibles.\n");
  return 0;
}