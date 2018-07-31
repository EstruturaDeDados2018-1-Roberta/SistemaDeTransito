#!/bin/sh
gcc -c interface.c -o interface.o
gcc -c main.c -o main.o
gcc -c mapa.c -o mapa.o
gcc -c utilitarios.c -o utilitarios.o
gcc interface.o main.o mapa.o utilitarios.o -o executavel
exit
