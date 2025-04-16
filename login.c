
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
int login(t_joueur *joueur)
{
  /*DEFINITION DES VARIABLES*/
  int essai =0;
  /*DEFINITION DES VARIABLES*/
  int couleur_texte = makecol(255,255,255);
  int x = 250; // abscisses de début du texte
  int y = 250; // ordonnées du début du texte

  for(essai=0;essai<3;essai++)
  {
    textprintf_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre nom d'utilisateur:\n");
    scanf("%s", joueur->user);
    if(strcmp(joueur->user,lecture_pseudo(joueur))==0)
    {
      //Pseudo invalide
      textprintf_ex(screen,font,x,y,couleur_texte,-1,"Votre nom d'utilisateur n'existes pas.\n");
      essai = essai - 1;
    }
    else
    {
      textprintf_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre mot de passe:\n");
      scanf("%c", joueur->mdp);
      for(essai=0;essai<3;essai++)
      {
        if(strcmp(joueur->user,lecture_mdp(joueur))==0)
        {
          textprintf_ex(screen,font,x,y,couleur_texte,-1,"mot de passe invalide.\n");
          essai = essai - 1;
        }
        else
        {
          textprintf_ex(screen,font,x,y,couleur_texte,-1,"connexion reussie.\n");
          // renvoie vers page de jeu (niveaux)
        }
      }
      textprintf_ex(screen,font,x,y,couleur_texte,-1,"Vous n'avez plus d'essais disponibles.\n");
      return 0;
    }
  }
  textprintf_ex(screen,font,x,y,couleur_texte,-1,"Vous n'avez plus d'essais disponibles.\n");
  return 0;
}