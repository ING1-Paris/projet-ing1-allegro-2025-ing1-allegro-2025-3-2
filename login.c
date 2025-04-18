
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
int login(t_joueur *joueur,BITMAP *background,char name)
{
  /*DEFINITION DES VARIABLES*/
  int essai =0;
  /*DEFINITION DES VARIABLES*/
  int couleur_texte = makecol(255,255,255);
  int x = SCREEN_W/2; // abscisses de début du texte
  int y = SCREEN_H/2; // ordonnées du début du texte

  for(essai=0;essai<3;essai++)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre nom d'utilisateur:\n");
    name[5] = "user";
    *joueur->user == ecrire_texte(joueur,name); // Equivalent du scanf mais en allegro : saisie du pseudo
    switch (readkey()>>8)
    {
      effacer_texte(background);// On efface la question
      effacer_texte(background);// : on efface le pseudo
      case KEY_ENTER: //Le joueur a validé son choix
      {
        //On vérifie le pseudo
        if (verifie_pseudo)
        {
          //Le pseudo existes.
          return 0;
        }
        else
        {
          essai++;// Le joueur perd un essai
        }
        break;
      }
      default:
      {
        essai++;// Le joueur perd un essai
        break;
      }
    }
    return 0;
  }

  if (essai == 3)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Attendre 30 secondes avant de recommencer.\n");
    rest(30000); // On attend 30 secondes
    effacer_texte(background);//On efface le texte précédent
    login(joueur,background);//On revient au début du programme
    return 0;
  }

  for (essai=0;essai<3;essai++)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre mot de passe:\n");
    //Equivalent du scanf mais en allegro
    name = "mdp";
    *joueur->mdp == ecrire_texte(joueur,name); // saisie du mot de passe
    switch (readkey()>>8)
    {
      effacer_texte(background);// On efface la question
      effacer_texte(background);// : on efface le mot de passe
      case KEY_ENTER:
      {
        /* ON VERIFIE QUE LE MOT DE PASSE ENTRE CORRESPOND A CELUI ATTENDU*/
        if (strcmp(joueur->mdp,lecture_joueur) != 0)
        {
          textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"mot de passe invalide.\n");
          rest(10000); // 10 secondes
          effacer_texte(background);// : on efface la question
          essai++; // le joueur perd un essai
        }
        else
        {
          textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"connexion reussie.\n");
          rest(10000); // 10 secondes
          effacer_texte(background);//On efface la question
          // Mot de passe valide : on va vers le menu du jeu (niveaux)
          return 0;
        }
        break;
      }
      default:
      {
        essai++;// Le joueur perd un essai
        break;
      }
    }
    return 0;
  }
  if (essai == 3)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Attendre 30 secondes avant de recommencer.\n");
    rest(30000); // On attend 30 secondes
    effacer_texte(background);//On efface le texte précédent
    login(joueur,background);//On revient au début du programme
    return 0;
  }
  return 0;
}