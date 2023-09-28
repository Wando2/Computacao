#include <stdio.h>
#include <stdlib.h>
#include "Bib1.h"

/* Interface padrão de pilha */
void Constroi(Pilha &P);
void Empilha(Pilha &P, int x);
int Desempilha(Pilha &P);
int Topo(Pilha &P);
int Tamanho(Pilha &P);
void constroe(Pilha &P){
	P.Topo = NULL; P.N = 0;
}
/* Interface padrão de pilha */

typedef struct Fila {
	Pilha P1,P2;
} Fila;

void Constroi(Fila &F) {
	constroe(F.P1);
	constroe(F.P2);
    
}

void Enfileira(Fila &F, int x) {
	while(Tamanho(F.P1) > 0){
        Empilha(F.P2,Desempilha(F.P1));
    }


	
    Empilha(F.P1,x);

    while(Tamanho(F.P2) > 0){
        Empilha(F.P1, Desempilha(F.P2));
    
    }

}

int Desenfileira(Fila &F) {
	
    return Desempilha(F.P1);
}

int Proximo(Fila &F) {
	
    return Topo(F.P1);

}

int Tamanho(Fila &F) {
	
    return Tamanho(F.P1);
}
int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	Fila F; Constroi(F);
	char op[2]; int e;
	while (scanf("%s", op)>0) {
		/* teste manual: 'i e' = enfileira o elemento e; 'r' = desenfileira, 'p' = consulta o próximo, 'n' = consulta o tamanho */
		if (op[0] == 'i') {
			scanf("%d", &e); Enfileira(F,e);
		} else if (op[0] == 'r') {
			printf("%d\n", Desenfileira(F));
		} else if (op[0] == 'p') {
			printf("%d\n", Proximo(F));
		} else if (op[0] == 'n') {
			printf("%d\n", Tamanho(F));
		} else {
			/* teste automático */
			for (int i=1; i<=1000; i++) {
				Enfileira(F,i);
			}	
			while (Tamanho(F) > 0) { 
				printf("%d ", Tamanho(F));
				printf("%d ", Proximo(F));
				printf("%d ", Desenfileira(F));
			}	
			printf("\n");
		}
	}

	return 0;
}