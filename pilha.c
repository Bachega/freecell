#include "pilha.h"

int vazia(Pilha* p) {
	return (p->topo==NULL);
}

Pilha* criarpilha() {
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

Pilha* push(Pilha* p, Carta info) {
	No* nova = (No*)malloc(sizeof(No));
	nova->info = info;
	nova->prox = p->topo;
	p->topo = nova;
	return p;
}

void setarpilha(Carta* c, Pilha* p, int n) {
    int i;
    for(i=0; i<n; i++) {
        p = push(p, c[i]);
    }
}

void transferir(Pilha* in, Pilha* out, int n) {
    int i;
    No* topo = out->topo;
    No* auxout = out->topo;
    for(i=1; i<n; i++) {
        auxout = auxout->prox;
    }

    out->topo = auxout->prox;
    auxout->prox = in->topo;
    in->topo = topo;

    topo = NULL; auxout = NULL;
    free(topo);
    free(auxout);
}

int checar(Pilha* in, Pilha* out, int n, int esp) {
    int i;
    No* auxout = out->topo;
    No* ant = out->topo;

    if(in->topo == out->topo) {return 0;}

    if((n-1)<=esp) {
        for(i=1; i<n; i++) {
            auxout = auxout->prox;

            if( !(((ant->info.n)%2 != (auxout->info.n)%2) && (ant->info.v == (auxout->info.v - 1))) ) {return 0;}

        }

        if(vazia(in)) {return 1;}

        if( ((in->topo->info.n)%2 != (auxout->info.n)%2) && (auxout->info.v == (in->topo->info.v - 1)) ) return 1;
    } else {
        return 0;
    }
}

Carta* pop(Pilha* p) {
    if(!vazia(p)) {
        Carta* c = (Carta*)malloc(sizeof(Carta));
        No* aux = p->topo;
        *c = p->topo->info;
        p->topo = p->topo->prox;
        free(aux);
        return c;
    } else {
        return NULL;
    }
}

void imprimepilhaaux(No* n, char* valor, char* naipe) {
    if(n){
        imprimepilhaaux(n->prox, valor, naipe);
		printf("%c - %c\n\n", valor[n->info.v], naipe[n->info.n]);
	}
}

void imprimepilha(Pilha* p, char* valor, char* naipe) {
    imprimepilhaaux(p->topo, valor, naipe);
}

int transferirespaco(Carta** e, Pilha* p, int m) {
    int r = 0;
    Carta* c = NULL;
    Carta* auxe = NULL;

    if(m==1) {
        if((*e)->v == -1) {
            auxe = *e;
            r = 1;
        }
    } else if(m==2) {
        if( (((*e)->n) == (p->topo->info.n)) && (((*e)->v) == ((p->topo->info.v) - 1)) ) {
            auxe = *e;
            r = 1;
        }
    }

    if(r) {
        c = pop(p);
        if(c) {
            *e = c;
        }
        free(auxe);
    }

    return r;

}

int transferirlivre(Carta** e, Pilha* p) {
    if((*e)->v == -1) return 0;

    if( vazia(p) || ((((*e)->n)%2 != (p->topo->info.n)%2) && ((*e)->v  == (p->topo->info.v - 1))) ) {
        Carta c;
        c.n = (*e)->n;
        c.v = (*e)->v;
        push(p, c);
        (*e)->v = -1;
        return 1;
    } else {
        return 0;
    }
}

int transferirlivrefinal(Carta** l, Carta** f) {
    if((*l)->v == -1) return 0;

    if( ( (*l)->n == (*f)->n ) && ( (*f)->v == ((*l)->v - 1) ) ) {
        (*f)->n = (*l)->n;
        (*f)->v = (*l)->v;
        (*l)->v = -1;
        return 1;
    } else {
        return 0;
    }
}

void salvarpilhaaux(No* n, FILE* arq) {
    if(!n) return;
    salvarpilhaaux(n->prox, arq);
    fwrite(&(n->info), sizeof(Carta), 1, arq);
}

void salvarpilha(Pilha* p, FILE* arq) {
    No* n = p->topo;
    salvarpilhaaux(n, arq);

    Carta c; c.v = -2;
    fwrite(&c, sizeof(Carta), 1, arq);
}

void carregarpilha(Pilha* p, FILE* arq) {
    Carta c;
    fread(&c, sizeof(Carta), 1, arq);
    while(c.v!=-2) {
        push(p, c);
        fread(&c, sizeof(Carta), 1, arq);
    }
}

void salvarespaco(Carta* e, FILE* arq) {
    fwrite(e, sizeof(Carta), 1, arq);
}

void carregarespaco(Carta* e, FILE* arq) {
    fread(e, sizeof(Carta), 1, arq);
}
