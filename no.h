#ifndef NO_H
#define NO_H

#include "carta.h"

typedef struct no {
	Carta info;
	struct no* prox;
}No;

#endif
