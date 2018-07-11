#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "mapa.h"
#include "utilitarios.h"

void desenhaMapa(mapa *cidade) {
	int a = 0, b = 0;
	for(a = 0; a < TAMANHO_DO_MAPA; a++) {
		for(b = 0; b < TAMANHO_DO_MAPA; b++) {
			if(cidade->casa[a][b]->local == RUA && cidade->casa[a][b]->local == SINAL) {
				if(cidade->casa[a][b]->estado == OCUPADO) {
					printf("1");
				} else if(cidade->casa[a][b]->estado == VAZIO) {
					printf("0");
				} else {
					printf("\n\tERRO EM DESENHAMAPA: ESTADO DA RUA || SINAL NAO RECONHECIDO");
				}
			} else if(cidade->casa[a][b]->local == CRUZAMENTO) {
				if(cidade->casa[a][b]->estado == OCUPADO) {
					printf("1");
				} else if(cidade->casa[a][b]->estado == VAZIO) {
					printf(" ");
				} else {
					printf("\n\tERRO EM DESENHAMAPA: ESTADO DO CRUZAMENTO NAO RECONHECIDO");
				}
			} else if(cidade->casa[a][b]->local == CONSTRUCAO) {
				printf(" ");
			} else {
				printf("\n\tERRO EM DESENHAMAPA: LOCAL DA CIDADE NAO RECONHECIDO");
			}
		}
		printf("\n");
	}
}
