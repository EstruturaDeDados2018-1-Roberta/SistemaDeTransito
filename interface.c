#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "mapa.h"
#include "utilitarios.h"

void desenhaMapa(mapa *cidade) {
	int x = 0, y = 0;
	for(x = 0; x < TAMANHO_DO_MAPA; x++) {
		for(y = 0; y < TAMANHO_DO_MAPA; y++) {
			if(cidade->casa[x][y]->local == RUA || cidade->casa[x][y]->local == SINAL) {
				if(cidade->casa[x][y]->estado == OCUPADO) {
					printf("1");
				} else if(cidade->casa[x][y]->estado == VAZIO) {
					printf("0");
				} else {
					printf("\n\tERRO EM DESENHAMAPA: ESTADO DA RUA || SINAL (%d,%d) NAO RECONHECIDO", x, y);
				}
			} else if(cidade->casa[x][y]->local == CRUZAMENTO) {
				if(cidade->casa[x][y]->estado == OCUPADO) {
					printf("1");
				} else if(cidade->casa[x][y]->estado == VAZIO) {
					printf(" ");
				} else {
					printf("\n\tERRO EM DESENHAMAPA: ESTADO DO CRUZAMENTO (%d,%d) NAO RECONHECIDO", x, y);
				}
			} else if(cidade->casa[x][y]->local == CONSTRUCAO) {
				printf(" ");
			} else {
				printf("\n\tERRO EM DESENHAMAPA: LOCAL (%d,%d) DA CIDADE NAO RECONHECIDO", x, y);
			}
		}
		printf("\n");
	}
}
