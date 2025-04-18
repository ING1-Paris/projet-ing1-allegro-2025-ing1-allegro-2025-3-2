#include <stdio.h>
#include <allegro.h>
#include "signin.h"
void initialisation_allegro();
int main()
{
    BITMAP*background;
    t_joueur *joueur;
    char name[5];
    initialisation_allegro();
    background = load_bitmap("C:\\Users\\galti\\CLionProjects\\exercice 2 BITMAP\\galaxie-andromede.bmp",NULL);
    if (!background)
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (key[KEY_ESC]) {
        login(joueur,background,name);
    }
    else {
        signin(joueur,background);
    }
}END_OF_MAIN();

void initialisation_allegro() {
    allegro_init(); // appel obligatoire (var.globales, recup. infos syst me ...)
    install_keyboard(); //pour utiliser le clavier
    install_mouse(); //pour utiliser la souris
    //pour choisir la profondeur de couleurs (8,16,24 ou 32 bits)
    set_color_depth(desktop_color_depth()); //ici : identique à celle du bureau

    //sélection du mode graphique
    // avec choix d'un driver+mode+résolution de l'écran
    /// si échec, le programme s'arrête
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}