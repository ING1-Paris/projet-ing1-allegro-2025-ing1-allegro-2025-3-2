
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

  for(essai=0;essai<3;essai++)
  {
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre nom d'utilisateur:\n");
    scanf("%s", joueur->user);
    if (keypressed() && key[KEY_ENTER] == 0)
    {
      //On efface le texte précédent
      effacer_texte(joueur,background);
      // Le joueur n'a pas validé son choix : il perd un essai
      essai++;
    }

    if (keypressed() && key[KEY_ENTER] == 1)// Le joueur a validé son choix
    {
      // On efface le texte précédent
      effacer_texte(joueur,background);

      /* VERIFICATION DE L'EXISTENCE DU PSEUDO*/

      if(strcmp(joueur->user,lecture_pseudo(joueur))!=0)
      {
        //Pseudo invalide
        textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Votre nom d'utilisateur n'existes pas.\n");
        rest(10000); // 10 secondes
        //On efface le message précédent
        effacer_texte(joueur,background);
        essai++; // le joueur perd un essai
      }
      else
      {
        // Pseudo valide : on sort de la boucle for
        return 0;
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
  }
  else
  {
    for (essai=0;essai<3;essai++) {
      textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Saisissez votre mot de passe:\n");
      scanf("%s", joueur->mdp);
      if (keypressed() && key[KEY_ENTER] == 0)
      {
        //On efface le texte précédent
        effacer_texte(joueur,background);
        // Le joueur n'a pas validé son choix : il perd un essai
        essai++;
      }
      if (keypressed() && key[KEY_ENTER] == 1) {
        //On efface le texte précédent
        effacer_texte(joueur,background);
        /* ON VERIFIE QUE LE MOT DE PASSE ENTRE CORRESPOND A CELUI ATTENDU*/
        if (strcmp(joueur->mdp,lecture_mdp(joueur)) != 0)
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
    }
    textprintf_centre_ex(screen,font,x,y,couleur_texte,-1,"Vous n'avez plus d'essais disponibles.\n");
    rest(30000); // 30 secondes
    //On efface le message précédent
    effacer_texte(joueur,background);
    //On retourne au début du programme
    login(joueur,background);
  }
  return 0;
}