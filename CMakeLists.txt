cmake_minimum_required(VERSION 3.30)
project(_ece_type C)

set(CMAKE_C_STANDARD 23)

add_executable(_ece_type main.c
        ecrire_texte.c
        effacer_texte.c
        charge_joueur.c
        verifie_joueur.c
        login.c
        signin.h)
target_link_libraries(${PROJECT_NAME} -lmingw32 -lalleg44)
