#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "casa.h"
#include "utilitarios.h"

void desenhaMapa(mapa *cidade[][TAMANHO_DO_MAPA]) {
	int a = 0, b = 0;
	for(a = 0; a < TAMANHO_DO_MAPA; a++) {
		for(b = 0; b < TAMANHO_DO_MAPA; b++) {
			if(cidade[a][b]->local == RUA && cidade[a][b]->local == SINAL) {
				if(cidade[a][b]->estado == OCUPADO) {
					printf("1");
				} else if(cidade[a][b]->estado == VAZIO) {
					printf("0");
				} else {
					printf("\n\tERRO EM DESENHAMAPA: ESTADO DA RUA || SINAL NAO RECONHECIDO");
				}
			} else if(cidade[a][b]->local == CRUZAMENTO) {
				if(cidade[a][b]->estado == OCUPADO) {
					printf("1");
				} else if(cidade[a][b]->estado == VAZIO) {
					printf(" ");
				} else {
					printf("\n\tERRO EM DESENHAMAPA: ESTADO DO CRUZAMENTO NAO RECONHECIDO");
				}
			} else {
				printf("\n\tERRO EM DESENHAMAPA: LOCAL DA CIDADE NAO RECONHECIDO");
			}
		}
		printf("\n");
	}
}
