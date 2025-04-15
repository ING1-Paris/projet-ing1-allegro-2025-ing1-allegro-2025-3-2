// Created by galti on 15/04/2025.
#include "signin.h"

int signin(t_joueur *joueur)
{
    // PSEUDO
    printf("Choisissez un pseudo:\n");
    scanf("%c", &joueur->user);
    if (joueur->user < 1 || joueur->user > 20){
      printf("Votre pseudo n'a pas le nombre de caracteres requis.\n");
    }
    else{         
    }
 return 0;
}
