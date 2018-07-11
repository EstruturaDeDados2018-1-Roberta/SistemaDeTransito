#include <stdio.h>
#include <stdlib.h>
#include "utilitarios.h"

void finalizaFrame() {
	#if linux || Linux || LINUX || UNIX
		printf("\e[H\e[2J");
		__fpurge(stdin);
	#elif defined WIN32
		system("cls");
		fflush(stdin);
	#else
		printf("\n\tERRO EM FINALIZAFRAME(): SISTEMA OPERACIONAL NAO RECONHECIDO\n");
	#endif
}
