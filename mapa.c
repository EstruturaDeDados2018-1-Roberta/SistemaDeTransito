#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "utilitarios.h"

casa* criaCasa(int local, int estado, int direcao[4], int sinal) {
	a = 0;
	casa *novaCasa = (casa*)malloc(sizeof(casa));
	novaCasa->local = local;
	novaCasa->estado = estado;
	novaCasa->direcao = direcao;
	novaCasa->sinal = sinal;
}

mapa* criaMapa() {
	mapa *novoMapa = (mapa*)malloc(sizeof(mapa));
	int a = 0, b = 0;
	for(a = 0; a < TAMANHO_DO_MAPA; a++) {
		for(b = 0; b < TAMANHO_DO_MAPA; b++) {
			if(a % 6 == 0 && b % 6 == 0) {
				novoMapa->casa[a][b] = criaCasa(CRUZAMENTO, VAZIO, {NULO}, NULO);
			} else {
				if(a == 0 || a == 6 || a == 12 || a == 18) {
					if(b == 1 || b == 5 || b == 7 || b == 11 || b == 13 || b == 17) {
						novoMapa->casa[a][b] = criaCasa(SINAL, VAZIO, {NULO}, AMARELO);
					} else {
						novoMapa->casa[a][b] = criaCasa(RUA, VAZIO, {NULO}, NULO);
					}
				} else if(a == 1 || a == 5 || a == 7 || a == 11 || a == 13 || a == 17) {
					if(b == 0 || b == 6 || b == 12 || b == 18) {
						novoMapa->casa[a][b] = criaCasa(SINAL, VAZIO, {NULO}, AMARELO);
					} else {
						novoMapa->casa[a][b] = criaCasa(CONSTRUCAO, NULO, {NULO}, AMARELO);
					}
				} else {
					if(b == 0 || b == 6 || b == 12 || b == 18) {
						novoMapa->casa[a][b] = criaCasa(RUA, VAZIO, {NULO}, NULO);
					}
				}
			}
		}
	}
}
