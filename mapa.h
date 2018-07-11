#define TAMANHO_DO_MAPA 19

typedef struct Casa casa;
typedef struct Mapa mapa;
struct Casa {
	int local;
	int estado;
	casa *direcao;
	int sinal;
};
struct Mapa {
	casa *casa[TAMANHO_DO_MAPA][TAMANHO_DO_MAPA];
}

casa* criaCasa();		//Cria nova casa
mapa* criaMapa();		//Cria o mapa inicializando todas as variaveis padronizadas
