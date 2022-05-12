#ifndef JOGO_H
#define JOGO_H

#include "cabecalho.h"

void jogo(int, char**);

void imprime(Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Carta*, Carta*, Carta*, Carta*, Carta*, Carta*, Carta*, Carta*);

void mover(Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Carta**, Carta**, Carta**, Carta**, Carta**, Carta**, Carta**, Carta**, int*);

void salvar(char*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Carta*, Carta*, Carta*, Carta*, Carta*, Carta*, Carta*, Carta*, int);

void carregar(char*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Pilha*, Carta*, Carta*, Carta*, Carta*, Carta*, Carta*, Carta*, Carta*, int*);

#endif
