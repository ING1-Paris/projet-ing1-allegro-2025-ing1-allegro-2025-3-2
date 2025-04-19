// Created by galti on 16/04/2025.

#ifndef SIGNIN_H
#define SIGNIN_H
#define LONGUEUR_MAX_PSEUDO 21
#define NOMBRE_MAX_PSEUDOS 100
#include <allegro.h>
#include <stdbool.h>

/*STRUCTURE DES INFORMATIONS ASSOCIEES AU JOUEUR*/
typedef struct joueur{
    char user[20];
    char mdp[12];
}t_joueur;

/* PROTOTYPES DES FONCTIONS DE CONNEXION*/
int signin(t_joueur *joueur,BITMAP*background);
int login(t_joueur *joueur,BITMAP*background,char *name);

/* PROTOTYPES DE LA FONCTION D'ECRITURE*/
char charge_joueur(t_joueur *joueur);

/* PROTOTYPES DE LA FONCTION DE LECTURE*/
bool verifie_joueur(t_joueur *joueur,char *name);

/* PROTOTYPES DES FONCTIONS DE TEXTE*/
char effacer_texte(BITMAP*background,char *texte);
char ecrire_texte(t_joueur *joueur,char *name);
#endif //SIGNIN_H
