#!/bin/sh
gcc -c interface.c -o interface.o
gcc -c utilitarios.c -o utilitarios.o
gcc interface.o utilitarios.o -o executavel
exit
