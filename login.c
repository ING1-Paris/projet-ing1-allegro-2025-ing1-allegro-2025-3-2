
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
int login(t_joueur *joueur,BITMAP *background,char *name)
{
  /*DEFINITION DES VARIABLES*/
  int essai =0;
  char texte[100];
  /*DEFINITION DES VARIABLES*/
  int couleur_texte = makecol(255,255,255);
  int x = SCREEN_W/2; // abscisses de début du texte
  int y = SCREEN_H/2; // ordonnées du début du texte

  for(essai=0;essai<3;essai++)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre nom d'utilisateur:\n");
    strcpy(name,"user");
    *joueur->user == ecrire_texte(joueur,name); // Equivalent du scanf mais en allegro : saisie du pseudo
    rest(30000); // On attend 30 secondes
    strcpy(texte,"Saisissez votre nom d'utilisateur:\n");
    effacer_texte(background,texte);// On efface la question
    strcpy(texte,joueur->user);
    effacer_texte(background,texte);// : on efface le pseudo

    switch (readkey()>>8)
    {
      case KEY_ENTER: //Le joueur a validé son choix
      {
        //On vérifie le pseudo
        if (verifie_joueur)
        {
          //Le pseudo existes.
          return joueur->user;
        }
        essai++;// Le joueur perd un essai
        break;
      }
      default:
      {
        essai++;// Le joueur perd un essai
        break;
      }
    }
    return joueur->user; // On doit vérifier si le mot de passe saisi par la suite est bien associé au pseudo
  }

  if (essai == 3)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Attendre 30 secondes avant de recommencer.\n");
    rest(30000); // On attend 30 secondes
    strcpy(texte,"Attendre 30 secondes avant de recommencer.\n");
    effacer_texte(background,texte);//On efface le texte précédent
    return login(joueur,background,name);//On revient au début du programme
  }

  for (essai=0;essai<3;essai++)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre mot de passe:\n");
    strcpy(name,"mdp");
    *joueur->mdp == ecrire_texte(joueur,name); // Equivalent du scanf mais en allegro : saisie du mot de passe
    rest(30000); // 30 secondes
    strcpy(texte,"Saisissez votre mot de passe:\n");
    effacer_texte(background,texte);// On efface la question
    strcpy(texte,joueur->mdp);
    effacer_texte(background,texte);// : on efface le mot de passe
    switch (readkey()>>8)
    {
      case KEY_ENTER:
      {
        /* ON VERIFIE QUE LE MOT DE PASSE ENTRE CORRESPOND A CELUI ATTENDU*/
        if (!verifie_joueur)
        {
          textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"mot de passe invalide.\n");
          rest(10000); // 10 secondes
          strcpy(texte,"mot de passe invalide.\n");
          effacer_texte(background,texte);// : on efface la question
          essai++; // le joueur perd un essai
        }
        else
        {
          textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"connexion reussie.\n");
          rest(10000); // 10 secondes
          strcpy(texte,"connexion reussie.\n");
          effacer_texte(background,texte);//On efface la question
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
    strcpy(texte,"Attendre 30 secondes avant de recommencer.\n");
    effacer_texte(background,texte);//On efface le texte précédent
    return login(joueur,background,name);//On revient au début du programme
  }
  return 0;
}