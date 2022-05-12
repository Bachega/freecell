#ifndef BARALHO_H
#define BARALHO_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "carta.h"


typedef struct {
	Carta* c;
}Baralho;

Baralho* criar();

void embaralhar(Baralho*);

void destruirbaralho(Baralho*);

#endif
