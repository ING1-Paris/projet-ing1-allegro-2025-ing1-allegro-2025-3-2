cmake_minimum_required(VERSION 3.30)

project(connexion_EceType C)

set(CMAKE_C_STANDARD 23)

add_executable(connexion_EceType main.c signin.c)
target_link_libraries(${PROJECT_NAME} -lmingw32 -lalleg44)
