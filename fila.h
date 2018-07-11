typedef struct Node node;
typedef struct Fila fila;
struct Node {
	int direcao;
	node *proximo;
};
struct Fila {
	node *cabeca;
	node *cauda;
};
