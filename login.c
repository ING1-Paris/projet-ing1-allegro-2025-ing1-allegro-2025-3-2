
// Created by galti on 16/04/2025.
#include <stdio.h>
#include <allegro.h>
#include "signin.h"
int login(t_joueur *joueur,BITMAP *background)
{
  /*DEFINITION DES VARIABLES*/
  int essai =0;
  /*DEFINITION DES VARIABLES*/
  int couleur_texte = makecol(255,255,255);
  int x = SCREEN_W/2; // abscisses de début du texte
  int y = SCREEN_H/2; // ordonnées du début du texte

  for(essai=0;essai<3;essai++) {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre nom d'utilisateur:\n");
    //Equivalent du scanf mais en allegro
    ecrire_texte(joueur); // s'occupe de la saisie du pseudo, en respectant la limite de caractères
    switch (readkey()>>8)
    {
      case KEY_ENTER: {
        //Le joueur a validé son choix : on efface le texte précédent
        effacer_texte(joueur,background);
        //On vérifie le pseudo et le mot de passe
        return 0;
      }
      default: {
        //On efface le texte précédent
        effacer_texte(joueur,background);
        // Le joueur n'a pas validé son choix : il perd un essai
        essai++;
      }
    }
  }
  textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Vous n'avez plus d'essais disponibles.\n");

  if (essai == 3)
  {
    // On efface le message précédent
    effacer_texte(joueur,background);
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Attendre 30 secondes avant de recommencer.\n");
    rest(30000); // On attend 30 secondes
    //On efface le texte précédent
    effacer_texte(joueur,background);
    //On revient au début du programme
    login(joueur,background);
    return 0;
  }
  else
  {
    for (essai=0;essai<3;essai++)
    {
      textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre mot de passe:\n");
      //Equivalent du scanf mais en allegro
      ecrire_texte(joueur); // s'occupe de la saisie du mot de passe, en respectant la limite de caractères
      switch (readkey()>>8)
      {
        case KEY_ENTER:
        {
          //On efface le texte précédent
          effacer_texte(joueur,background);
          /* ON VERIFIE QUE LE MOT DE PASSE ENTRE CORRESPOND A CELUI ATTENDU*/
          if (strcmp(joueur->mdp,lecture_mdp) != 0)
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
            // Mot de passe valide : on sort de la boucle for
            return 0;
          }
        }
        default: {
          //On efface le texte précédent
          effacer_texte(joueur,background);
          // Le joueur n'a pas validé son choix : il perd un essai
          essai++;
        }
      }
    }
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Vous n'avez plus d'essais disponibles.\n");
    rest(30000); // 30 secondes
    //On efface le message précédent
    effacer_texte(joueur,background);
    //On retourne au début du programme
    login(joueur,background);
  }
}