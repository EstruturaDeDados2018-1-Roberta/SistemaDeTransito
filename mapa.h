#define TAMANHO_DO_MAPA 19

typedef struct Casa casa;
typedef struct Mapa mapa;
struct Casa {
	int local;
	int estado;
	int direcao[4];
	int sinal;
};
struct Mapa {
	casa *casa[TAMANHO_DO_MAPA][TAMANHO_DO_MAPA];
};

casa* criaCasa(int local, int estado, int direcao[4], int sinal);		//Cria nova casa
mapa* criaMapa();		//Cria o mapa inicializando todas as variaveis padronizadas
