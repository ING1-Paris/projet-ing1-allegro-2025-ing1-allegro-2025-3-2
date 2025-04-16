// Created by galti on 15/04/2025.

#ifndef SIGNIN_H
#define SIGNIN_H
/*STRUCTURE DES INFORMATIONS ASSOCIEES AU JOUEUR*/
typedef struct joueur{
char user[20];
char mdp[12];
}t_joueur;

/* PROTOTYPES DES FONCTIONS DE CONNEXION*/
int signin(t_joueur *joueur);
#endif //SIGNIN_H
