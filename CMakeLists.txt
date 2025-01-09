cmake_minimum_required(VERSION 3.16)
project(Mini_Projet C)

set(CMAKE_C_STANDARD 99)

# Ajoutez tous les fichiers sources ici
add_executable(Mini_Projet
        AppTest/apptest.c
        AppTest/test.c
        )
