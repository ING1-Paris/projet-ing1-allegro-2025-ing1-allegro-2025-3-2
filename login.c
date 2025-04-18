
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
int login(t_joueur *joueur,BITMAP *background)
{
  /*DEFINITION DES VARIABLES*/
  int essai =0;
  char pseudos[NOMBRE_MAX_PSEUDOS][LONGUEUR_MAX_PSEUDO]; // Tableau de pseudos
  /*DEFINITION DES VARIABLES*/
  int couleur_texte = makecol(255,255,255);
  int x = SCREEN_W/2; // abscisses de début du texte
  int y = SCREEN_H/2; // ordonnées du début du texte

  for(essai=0;essai<3;essai++)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre nom d'utilisateur:\n");
    //Equivalent du scanf mais en allegro
    ecrire_texte(joueur); // saisie du pseudo
    switch (readkey()>>8)
    {
      case KEY_ENTER:
      {
        //Le joueur a validé son choix : on efface le texte précédent
        effacer_texte(joueur,background);
        //On vérifie le pseudo
        if (ustrstr(joueur->user,pseudos)!= NULL)
        {
          //Le pseudo existes.
          return 0;
        }
        else
        {
          // Le pseudo entré n'existes pas : on revient au début
          login(joueur,background);
          // Le joueur perd un essai
          essai++;
        }
      }
      default:
      {
        //On efface le texte précédent
        effacer_texte(joueur,background);
        // Le joueur n'a pas validé son choix : il perd un essai
        essai++;
      }
    }
  }

  if (essai == 3)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Attendre 30 secondes avant de recommencer.\n");
    rest(30000); // On attend 30 secondes
    //On efface le texte précédent
    effacer_texte(joueur,background);
    //On revient au début du programme
    login(joueur,background);
    return 0;
  }

  for (essai=0;essai<3;essai++)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre mot de passe:\n");
    //Equivalent du scanf mais en allegro
    ecrire_texte(joueur); // saisie du mot de passe
    switch (readkey()>>8)
    {
      case KEY_ENTER:
      {
        //On efface le texte précédent
        effacer_texte(joueur,background);
        /* ON VERIFIE QUE LE MOT DE PASSE ENTRE CORRESPOND A CELUI ATTENDU*/
        if (strcmp(joueur->mdp,lecture_joueur) != 0)
        {
          // Le mot de passe est invalide
          textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"mot de passe invalide.\n");
          rest(10000); // 10 secondes
          //On efface le message précédent
          effacer_texte(joueur,background);
          essai++;
        }
        else
        {
          // Connexion réussie
          textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"connexion reussie.\n");
          rest(10000); // 10 secondes
          //On efface le message précédent
          effacer_texte(joueur,background);
          // Mot de passe valide : on va vers le menu du jeu (niveaux)
          return 0;
        }
      }
      default:
      {
        //On efface le texte précédent
        effacer_texte(joueur,background);
        // Le joueur n'a pas validé son choix : il perd un essai
        essai++;
      }
    }
  }
  if (essai == 3)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Attendre 30 secondes avant de recommencer.\n");
    rest(30000); // On attend 30 secondes
    //On efface le texte précédent
    effacer_texte(joueur,background);
    //On revient au début du programme
    login(joueur,background);
    return 0;
  }
}