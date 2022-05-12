#include "jogo.h"

void jogo(int i, char* f[]) {
    char t[32];

    Carta* ouros = (Carta*)malloc(sizeof(Carta)); //0
    Carta* copas = (Carta*)malloc(sizeof(Carta)); //2
    ouros->v = -1; ouros->n = 0; copas->v = -1; copas->n = 2;

    Carta* espadas = (Carta*)malloc(sizeof(Carta)); //1
    Carta* paus = (Carta*)malloc(sizeof(Carta)); //3
    espadas->v = -1; espadas->n = 1; paus->v = -1; paus->n = 3;

    Carta* livre1 = (Carta*)malloc(sizeof(Carta));
    Carta* livre2 = (Carta*)malloc(sizeof(Carta));
    Carta* livre3 = (Carta*)malloc(sizeof(Carta));
    Carta* livre4 = (Carta*)malloc(sizeof(Carta));
    livre1->v = -1; livre2->v = -1; livre3->v = -1; livre4->v = -1;

    Pilha* p1 = criarpilha();
	Pilha* p2 =  criarpilha();
	Pilha* p3 = criarpilha();
	Pilha* p4 =  criarpilha();
	Pilha* p5 = criarpilha();
	Pilha* p6 =  criarpilha();
	Pilha* p7 = criarpilha();
	Pilha* p8 =  criarpilha();

	int esp = 4;

    if(i==1) {
        carregar(f[1], p1, p2, p3, p4, p5, p6, p7, p8, livre1, livre2, livre3, livre4, ouros, copas, espadas, paus, &esp);
    } else {
        Baralho* b = criar();
        embaralhar(b);

        setarpilha(&b->c[0], p1, 7);
        setarpilha(&b->c[7], p2, 7);
        setarpilha(&b->c[14], p3, 7);
        setarpilha(&b->c[21], p4, 7);
        setarpilha(&b->c[28], p5, 6);
        setarpilha(&b->c[34], p6, 6);
        setarpilha(&b->c[40], p7, 6);
        setarpilha(&b->c[46], p8, 6);

        destruirbaralho(b);

    }

    int sv = 0;
    int ex = 1;

    while(ex) {
        imprime(p1, p2, p3, p4, p5, p6 ,p7 ,p8, livre1, livre2, livre3, livre4, ouros, copas, espadas, paus);
        printf("0 - Sair  ||  1 - Mover\n");
        scanf("%d", &ex);fflush(stdin);
        printf("\n\n");
        switch(ex) {
        case 1:
            mover(p1, p2, p3, p4, p5, p6, p7 , p8, &livre1, &livre2, &livre3, &livre4, &ouros, &copas, &espadas, &paus, &esp);
            break;
        case 0:
            printf("Deseja salvar o jogo? 1- Sim / 0- Nao\n"); scanf("%d", &sv);fflush(stdin);
            if(sv==1) {
                if(!f[1]) {
                    printf("\nDigite o nome do save (junto com a extensao .bin)\n"); fgets(t, 32, stdin); strtok(t, "\n"); fflush(stdin);
                    salvar(t, p1, p2, p3, p4, p5, p6 ,p7 , p8, livre1, livre2, livre3, livre4, ouros, copas, espadas, paus, esp);
                } else {
                    salvar(f[1], p1, p2, p3, p4, p5, p6 ,p7 , p8, livre1, livre2, livre3, livre4, ouros, copas, espadas, paus, esp);
                }
            }
            break;
        }
    }
}

void imprime(Pilha* p1, Pilha* p2, Pilha* p3, Pilha* p4, Pilha* p5, Pilha* p6, Pilha* p7, Pilha* p8, Carta* livre1, Carta* livre2, Carta* livre3, Carta* livre4, Carta* ouros, Carta* copas, Carta* espadas, Carta* paus) {
    char valor[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K' };
	char naipe[4] = {'O', 'E', 'C', 'P'};

    //printf("\n\n\n\n");
    system("cls");
    printf("\n");

    printf("L1: "); if(livre1->v != -1) printf("%c - %c", valor[livre1->v], naipe[livre1->n]); printf("  ");
    printf("L2: "); if(livre2->v != -1) printf("%c - %c", valor[livre2->v], naipe[livre2->n]); printf("  ");
    printf("L3: "); if(livre3->v != -1) printf("%c - %c", valor[livre3->v], naipe[livre3->n]); printf("  ");
    printf("L4: "); if(livre4->v != -1) printf("%c - %c", valor[livre4->v], naipe[livre4->n]); printf("  ");

    printf("      ||      ");

    printf("O: "); if(ouros->v != -1) printf("%c - %c", valor[ouros->v], naipe[ouros->n]); printf("  ");
    printf("C: "); if(copas->v != -1) printf("%c - %c", valor[copas->v], naipe[copas->n]); printf("  ");
    printf("E: "); if(espadas->v != -1) printf("%c - %c", valor[espadas->v], naipe[espadas->n]); printf("  ");
    printf("P: "); if(paus->v != -1) printf("%c - %c", valor[paus->v], naipe[paus->n]); printf("  ");

    printf("\n\n\n");

    printf("|| 1 ||\n\n");imprimepilha(p1, valor, naipe); printf("\n\n\n");
    printf("|| 2 ||\n\n");imprimepilha(p2, valor, naipe); printf("\n\n\n");
    printf("|| 3 ||\n\n");imprimepilha(p3, valor, naipe); printf("\n\n\n");
    printf("|| 4 ||\n\n");imprimepilha(p4, valor, naipe); printf("\n\n\n");
    printf("|| 5 ||\n\n");imprimepilha(p5, valor, naipe); printf("\n\n\n");
    printf("|| 6 ||\n\n");imprimepilha(p6, valor, naipe); printf("\n\n\n");
    printf("|| 7 ||\n\n");imprimepilha(p7, valor, naipe); printf("\n\n\n");
    printf("|| 8 ||\n\n");imprimepilha(p8, valor, naipe); printf("\n\n\n");
}

void mover(Pilha* p1, Pilha* p2, Pilha* p3, Pilha* p4, Pilha* p5, Pilha* p6, Pilha* p7, Pilha* p8, Carta** livre1, Carta** livre2, Carta** livre3, Carta** livre4, Carta** ouros, Carta** copas, Carta** espadas, Carta** paus, int* esp) {

    int op, ne, nf, m, nin, nout, numcarta;
    Carta** e = NULL;
    Carta** f = NULL;
    No* in = NULL;
    No* out = NULL;

    printf("1- Mover entre pilhas || 2- Mover de pilha para um espaco livre/final ||\n3- Mover de um espaco livre para pilha || 4- Mover de um espaco livre para final\n");
    scanf("%d", &op); fflush(stdin);printf("\n");

    if(op==1) {
        printf("Escreva o numero da pilha de saida, o numero da pilha de destino\ne a quantidade de cartas que deseja mover:\n");
        scanf("%d%d%d", &nout, &nin, &numcarta); fflush(stdin);

        switch(nin) {
        case 1:
            in = p1;
            break;
        case 2:
            in = p2;
            break;
        case 3:
            in = p3;
            break;
        case 4:
            in = p4;
            break;
        case 5:
            in = p5;
            break;
        case 6:
            in = p6;
            break;
        case 7:
            in = p7;
            break;
        case 8:
            in = p8;
            break;
        }

        switch(nout) {
        case 1:
            out = p1;
            break;
        case 2:
            out = p2;
            break;
        case 3:
            out = p3;
            break;
        case 4:
            out = p4;
            break;
        case 5:
            out = p5;
            break;
        case 6:
            out = p6;
            break;
        case 7:
            out = p7;
            break;
        case 8:
            out = p8;
            break;
        }

        if(checar(in, out, numcarta, esp)) {
            transferir(in, out, numcarta);
        } else {
            printf("\n\nNao foi possivel mover\n\n\n"); system("pause");
        }
    } else if(op==2) {
        printf("\nDigite o numero da pilha de saida e numero do espaco que recebe a carta\n\n");
        printf("1- L1 || 2- L2 || 3- L3 || 4- L4 || 5- O || 6- E || 7- C || 8- P\n");
        scanf("%d%d", &nout, &ne); fflush(stdin);

        switch(nout) {
        case 1:
            out = p1;
            break;
        case 2:
            out = p2;
            break;
        case 3:
            out = p3;
            break;
        case 4:
            out = p4;
            break;
        case 5:
            out = p5;
            break;
        case 6:
            out = p6;
            break;
        case 7:
            out = p7;
            break;
        case 8:
            out = p8;
            break;
        }

        switch(ne) {
        case 1:
            e = livre1; m = 1;
            break;
        case 2:
            e = livre2; m = 1;
            break;
        case 3:
            e = livre3; m = 1;
            break;
        case 4:
            e = livre4; m = 1;
            break;
        case 5:
            e = ouros; m = 2;
            break;
        case 6:
            e = espadas; m = 2;
            break;
        case 7:
            e = copas; m = 2;
            break;
        case 8:
            e = paus; m = 2;
            break;
        }

        if(!transferirespaco(e, out, m)) {
            printf("\n\nNao foi possivel mover\n\n\n"); system("pause");
        } else {
            if(m==1){(*esp)--;}
        }

    } else if(op==3) {
        printf("Digite o numero do espaco e o numero da pilha que recebe a carta\n\n");
        printf("1- L1 || 2- L2 || 3- L3 || 4- L4\n");
        scanf("%d%d", &ne, &nout); fflush(stdin);

        switch(nout) {
        case 1:
            out = p1;
            break;
        case 2:
            out = p2;
            break;
        case 3:
            out = p3;
            break;
        case 4:
            out = p4;
            break;
        case 5:
            out = p5;
            break;
        case 6:
            out = p6;
            break;
        case 7:
            out = p7;
            break;
        case 8:
            out = p8;
            break;
        }

        switch(ne) {
        case 1:
            e = livre1;
            break;
        case 2:
            e = livre2;
            break;
        case 3:
            e = livre3;
            break;
        case 4:
            e = livre4;
            break;
        }

        if(!transferirlivre(e, out)) {
            printf("\n\nNao foi possivel mover\n\n\n"); system("pause");
        } else {
            (*esp)++;
        }

    } else if(op==4) {
        printf("\nDigite o numero do espaco livre e numero do espaco final que recebe a carta\n\n");
        printf("1- L1 || 2- L2 || 3- L3 || 4- L4 -->> 5- O || 6- E || 7- C || 8- P\n");
        scanf("%d%d", &ne, &nf); fflush(stdin);

        switch(ne) {
        case 1:
            e = livre1;
            break;
        case 2:
            e = livre2;
            break;
        case 3:
            e = livre3;
            break;
        case 4:
            e = livre4;
            break;
        }

        switch(nf) {
        case 5:
            e = ouros; m = 2;
            break;
        case 6:
            e = espadas; m = 2;
            break;
        case 7:
            e = copas; m = 2;
            break;
        case 8:
            e = paus; m = 2;
            break;
        }

        if(!transferirlivrefinal(e, f)) {
            printf("\n\nNao foi possivel mover\n\n\n"); system("pause");
        } else {
            (*esp)++;
        }
    }

}

void salvar(char* f, Pilha* p1, Pilha* p2, Pilha* p3, Pilha* p4, Pilha* p5, Pilha* p6, Pilha* p7, Pilha* p8, Carta* livre1, Carta* livre2, Carta* livre3, Carta* livre4, Carta* ouros, Carta* copas, Carta* espadas, Carta* paus, int esp) {
    FILE* arq;
    arq = fopen(f, "wb");

    if(!arq) {
        printf("Nao foi possivel salvar\n");
        return;
    }

    salvarpilha(p1, arq);
    salvarpilha(p2, arq);
    salvarpilha(p3, arq);
    salvarpilha(p4, arq);
    salvarpilha(p5, arq);
    salvarpilha(p6, arq);
    salvarpilha(p7, arq);
    salvarpilha(p8, arq);

    salvarespaco(livre1, arq);
    salvarespaco(livre2, arq);
    salvarespaco(livre3, arq);
    salvarespaco(livre4, arq);
    salvarespaco(ouros, arq);
    salvarespaco(espadas, arq);
    salvarespaco(copas, arq);
    salvarespaco(paus, arq);

    fwrite(&esp, sizeof(int), 1, arq);

    fclose(arq);
}

void carregar(char* f, Pilha* p1, Pilha* p2, Pilha* p3, Pilha* p4, Pilha* p5, Pilha* p6, Pilha* p7, Pilha* p8, Carta* livre1, Carta* livre2, Carta* livre3, Carta* livre4, Carta* ouros, Carta* copas, Carta* espadas, Carta* paus, int* esp) {
	FILE* arq;

    arq = fopen(f, "rb");

    if(!arq) {
        printf("Nao foi possivel carregar\n");
        return;
    }

    carregarpilha(p1, arq);
    carregarpilha(p2, arq);
    carregarpilha(p3, arq);
    carregarpilha(p4, arq);
    carregarpilha(p5, arq);
    carregarpilha(p6, arq);
    carregarpilha(p7, arq);
    carregarpilha(p8, arq);

    carregarespaco(livre1, arq);
    carregarespaco(livre2, arq);
    carregarespaco(livre3, arq);
    carregarespaco(livre4, arq);
    carregarespaco(ouros, arq);
    carregarespaco(espadas, arq);
    carregarespaco(copas, arq);
    carregarespaco(paus, arq);

    fread(esp, sizeof(int), 1, arq);

    fclose(arq);

}

