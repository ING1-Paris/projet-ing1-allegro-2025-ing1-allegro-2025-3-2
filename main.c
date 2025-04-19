#include <stdio.h>
#include <allegro.h>
#include "signin.h"
void initialisation_allegro();
int main()
{
    t_joueur *joueur;
    char name[5];
    initialisation_allegro();
    BITMAP*background = load_bitmap("C:\\HORTENSE GALTIER\\2024-2025 ING1 ECE\\INFORMATIQUE\\SEMESTRE 2\\COURS 4 ALLEGRO\\galaxie-andromede.bmp",NULL);
    if (!background)
    {
        allegro_message("pas pu trouver/charger mon_image.bmp");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    joueur = malloc(sizeof(t_joueur));
    if (!joueur)
    {
        allegro_message("pas pu allouer de la memoire");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    blit(background,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    readkey();
    while (!key[KEY_ESC])
    {
        switch (readkey() >> 8)
        {
            case KEY_ENTER:
            {
                signin(joueur,background);
                free(joueur);
                break;
            }
            default: {
                login(joueur,background,name);
                free(joueur);
                break;
            }
        }
    }
    allegro_exit();
    return 0;

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