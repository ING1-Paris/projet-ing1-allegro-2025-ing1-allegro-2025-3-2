//
// Created by galti on 16/04/2025.
//

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
int signin(t_joueur *joueur);
int charge_pseudo(t_joueur *joueur);
int charge_mdp(t_joueur *joueur);
int login(t_joueur *joueur);
int lecture_pseudo(t_joueur *joueur);
int lecture_mdp(t_joueur *joueur);
#endif //SIGNIN_H
