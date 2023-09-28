#include <stdio.h>
#include <stdlib.h>
#include "Bib1.h"

/* Interface padrão de pilha */
void Constroi(Pilha &P);
void Empilha(Pilha &P, int x);
int Desempilha(Pilha &P);
int Topo(Pilha &P);
int Tamanho(Pilha &P);
/* Interface padrão de pilha */

void Ordena(Pilha &P) {
	Pilha Q; Constroi(Q);

	int tamanho = (Tamanho(P));
	
	// o tamanho se refere ao tamanho de elementos desorganizados. a cada vez que loop executa, esse tamanho diminui	

	while (tamanho > 0) {
		int maiorElemento = Desempilha(P);
		tamanho--;
		
		for(int i = 0; i < tamanho; i++){  // encontra o maior elemento atual e coloca todos os menores na lista aux, esvaziando o P
			if(Topo(P) > maiorElemento){
				Empilha(Q, maiorElemento);
				maiorElemento = Desempilha(P);
			}

			else{
				Empilha(Q,Desempilha(P));
			}
		}

		Empilha(P,maiorElemento); // coloca o maior no topo da lista vazia, e depois reinsere todos os demais elementos, assim deixando o maior elemento no final

		for(int j = 0; j < tamanho; j++){
			Empilha(P,Desempilha(Q));
		}
	}


}

void Escreve(Pilha &P) {
		while (Tamanho(P) > 0) {
			printf("%d ", Desempilha(P));
		}
		printf("\n");
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	Pilha P; Constroi(P);
	int n; int e;
	while (scanf("%d", &n)>0) {
		if (n>=0) {
			/* teste manual: 'n e_1 ... e_n' */
			for (int i=1; i<=n; i++) {
				scanf("%d", &e); Empilha(P,e);
			}
			Ordena(P); Escreve(P);
		} else {
			/* teste automático */
			if (n==-1) {
				for (int i=1; i<=1000; i++) {
					Empilha(P,i+(1001)*(i%2));
				}	
			} else {
				for (int i=1; i<=1000; i++) {
					Empilha(P,i+(1001)*(i%5==0 ? 0 : 1));
				}	
			}
			Ordena(P); Escreve(P);
		}
	}

	return 0;
}