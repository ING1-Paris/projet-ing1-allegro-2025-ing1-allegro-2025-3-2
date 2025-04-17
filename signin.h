// Created by galti on 16/04/2025.

#ifndef SIGNIN_H
#define SIGNIN_H
#define LONGUEUR_MAX_PSEUDO 21
#define NOMBRE_MAX_PSEUDOS 100
/*STRUCTURE DES INFORMATIONS ASSOCIEES AU JOUEUR*/
typedef struct joueur{
    char user[20];
    char mdp[12];
}t_joueur;

/* PROTOTYPES DES FONCTIONS DE CONNEXION*/
int signin(t_joueur *joueur,BITMAP*background);
int login(t_joueur *joueur,BITMAP*background);

/* PROTOTYPES DES FONCTIONS D'ECRITURE*/
char charge_joueur(t_joueur *joueur);
char verifie_pseudo(t_joueur *joueur);

/* PROTOTYPES DES FONCTIONS DE LECTURE*/
int lecture_joueur(t_joueur *joueur);

/* PROTOTYPES DE LA FONCTION QUI EFFACES LE TEXTE*/
void effacer_texte(t_joueur *joueur,BITMAP*background);
void ecrire_texte(t_joueur *joueur);
#endif //SIGNIN_H
