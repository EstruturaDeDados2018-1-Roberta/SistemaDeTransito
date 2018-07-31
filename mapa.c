#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "utilitarios.h"

casa* criaCasa(int local, int estado, int direcao[4], int sinal) {
	int a = 0;
	casa *novaCasa = (casa*)malloc(sizeof(casa));
	novaCasa->local = local;
	novaCasa->estado = estado;
	for(a = 0; a < 4; a++) {
		novaCasa->direcao[a] = direcao[a];
	}
	novaCasa->sinal = sinal;
	return novaCasa;
}

mapa* criaMapa() {
	mapa *novoMapa = (mapa*)malloc(sizeof(mapa));
	int x = 0, y = 0;
	int norte[4] = {1,0,0,0};
	int sul[4] = {0,1,0,0};
	int leste[4] = {0,0,1,0};
	int oeste[4] = {0,0,0,1};
	int norteELeste[4] = {1,0,1,0};
	int norteEOeste[4] = {1,0,0,1};
	int sulELeste[4] = {0,1,1,0};
	int sulEOeste[4] = {0,1,0,1};
	int nulo[4] = {0,0,0,0};
	for(x = 0; x < TAMANHO_DO_MAPA; x++) {
		for(y = 0; y < TAMANHO_DO_MAPA; y++) {
			if(x % 6 == 0 && y % 6 == 0) {
				if(x == 0) {
					if(y == 0) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, sul, NULO);
					} else if(y == 6 || y == 18) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, oeste, NULO);
					} else if(y == 12) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, sulEOeste, NULO);
					} else {
						printf("\n\tERRO EM CRIAMAPA: POSICAO (%d,%d) NAO MAPEADA", x, y);
					}
				} else if(x == 6) {
					if(y == 0 || y == 12) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, sulELeste, NULO);
					} else if(y == 6) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, norteELeste, NULO);
					} else if(y == 18) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, norte, NULO);
					} else {
						printf("\n\tERRO EM CRIAMAPA: POSICAO (%d,%d) NAO MAPEADA", x, y);
					}
				} else if(x == 12) {
					if(y == 0) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, sul, NULO);
					} else if(y == 6 || y == 18) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, norteEOeste, NULO);
					} else if(y == 12) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, sulEOeste, NULO);
					} else {
						printf("\n\tERRO EM CRIAMAPA: POSICAO (%d,%d) NAO MAPEADA", x, y);
					}
				} else if(x == 18) {
					if(y == 0 || y == 12) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, leste, NULO);
					} else if(y == 6) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, norteELeste, NULO);
					} else if(y == 18) {
						novoMapa->casa[x][y] = criaCasa(CRUZAMENTO, VAZIO, norte, NULO);
					} else {
						printf("\n\tERRO EM CRIAMAPA: POSICAO (%d,%d) NAO MAPEADA", x, y);
					}
				} else {
					printf("\n\tERRO EM CRIAMAPA: POSICAO (%d,%d) NAO MAPEADA", x, y);
				}
			} else {
				if(x == 0 || x == 12) {
					if(y == 1 || y == 7 || y == 13) {
						novoMapa->casa[x][y] = criaCasa(SINAL, VAZIO, oeste, AMARELO);
					} else if(y != 0 && y != 6 && y != 12 && y != 18) {
						novoMapa->casa[x][y] = criaCasa(RUA, VAZIO, oeste, NULO);
					}
				} else if(x == 1 || x == 7 || x == 13) {
					if(y == 6 || y == 18) {
						novoMapa->casa[x][y] = criaCasa(SINAL, VAZIO, norte, AMARELO);
					} else if(y == 0 || y == 12) {
						novoMapa->casa[x][y] = criaCasa(RUA, VAZIO, sul, NULO);
					} else {
						novoMapa->casa[x][y] = criaCasa(CONSTRUCAO, NULO, nulo, NULO);
					}
				} else if(x == 5 || x == 11 || x == 17) {
					if(y == 0 || y == 12) {
						novoMapa->casa[x][y] = criaCasa(SINAL, VAZIO, sul, AMARELO);
					} else if(y == 6 || y == 18) {
						novoMapa->casa[x][y] = criaCasa(RUA, VAZIO, norte, NULO);
					} else {
						novoMapa->casa[x][y] = criaCasa(CONSTRUCAO, NULO, nulo, NULO);
					}
				} else if(x == 6 || x == 18) {
					if(y == 5 || y == 11 || y == 17) {
						novoMapa->casa[x][y] = criaCasa(SINAL, VAZIO, leste, AMARELO);
					} else if(y != 0 && y != 6 && y != 12 && y != 18) {
						novoMapa->casa[x][y] = criaCasa(RUA, VAZIO, leste, NULO);
					}
				} else if (x == 2 || x == 3 || x == 4 || x == 8 || x == 9 || x == 10 || x == 14 || x == 15 || x == 16){
					if(y == 0 || y == 12) {
						novoMapa->casa[x][y] = criaCasa(RUA, VAZIO, sul, NULO);
					} else if(y == 6 || y == 18) {
						novoMapa->casa[x][y] = criaCasa(RUA, VAZIO, norte, NULO);
					} else {
						novoMapa->casa[x][y] = criaCasa(CONSTRUCAO, NULO, nulo, NULO);
					}
				} else {
					printf("\n\tERRO EM CRIAMAPA: POSICAO (%d,%d) NAO MAPEADA", x, y);
				}
			}
		}
	}
	return novoMapa;
}
