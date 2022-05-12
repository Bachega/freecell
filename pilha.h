#ifndef PILHA_H
#define PILHA_H

#include <stdlib.h>
#include <stdio.h>

#include "no.h"

typedef struct {
	No* topo;
}Pilha;

int vazia(Pilha*);

Pilha* criarpilha();

Pilha* push(Pilha*, Carta);

void setarpilha(Carta*, Pilha*, int);

void transferir(Pilha*, Pilha*, int);

int checar(Pilha*, Pilha*, int, int);

Carta* pop(Pilha*);

void imprimepilhaaux(No*, char*, char*);

void imprimepilha(Pilha*, char*, char*);

int transferirespaco(Carta**, Pilha*, int);

int transferirlivre(Carta**, Pilha*);

int transferirlivrefinal(Carta**, Carta**);

void salvarpilhaaux(No*, FILE*);

void salvarpilha(Pilha*, FILE*);

void carregarpilha(Pilha*, FILE*);

void salvarespaco(Carta*, FILE*);

void carregarespaco(Carta*, FILE*);

#endif
