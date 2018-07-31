#include <stdio.h>
#include <stdlib.h>
#include "carro.h"
#include "interface.h"
#include "main.h"
#include "mapa.h"
#include "utilitarios.h"

int main() {
	mapa *cidade = criaMapa();
	desenhaMapa(cidade);
}
