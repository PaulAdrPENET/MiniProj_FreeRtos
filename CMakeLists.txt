cmake_minimum_required(VERSION 3.16)
project(Mini_Projet C)

set(CMAKE_C_STANDARD 99)

# Ajoutez tous les fichiers sources ici
add_executable(Mini_Projet
        TEST/test_frame.c
        mux_demux.c mux_demux.h parser.c parser.h byte.c byte.h trame.c trame.h signal.c signal.h main.c main.h TEST/test.c TEST/test.h TEST/test_signal.c TEST/test_signal.h TEST/test_byte.c TEST/test_byte.h TEST/test_mux_demux.c TEST/test_mux_demux.h)
