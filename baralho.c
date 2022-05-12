#include "baralho.h"

Baralho* criar() {
	int i, j=0;
	Baralho* b = (Baralho*)malloc(sizeof(Baralho));
	b->c = (Carta*)malloc(sizeof(Carta)*52);

	for(i=0; i<4; i++) {
		for(j=0; j<13; j++) {
			b->c[i*13 + j].v = j;
			b->c[i*13 + j].n = i;
		}
	}

	return b;
}

void destruirbaralho(Baralho* b) {
    free(b->c);
    free(b);
    b = NULL;
}

void embaralhar(Baralho* b) {
	int i, j; Carta aux;
	srand(time(NULL));
	for (i=0; i < 52; i++) {
		j = rand() % 52;
		aux = b->c[j];
		b->c[j] = b->c[i];
		b->c[i] = aux;
	}
}
