#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int NumeroElementos(No * L) {
	No * p = L;
    int contador = 0;
    while(p != NULL){
        contador += 1;
        p = p->Prox;
    }

    return contador;
}

void Insere(No * &L, int e) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e;
	novo->Prox = L;
	L = novo;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	No * L = NULL; 
	char op[2]; int e, k;
	while (scanf("%s", op)>0) {
		if (op[0] != 'a') {
			/* teste manual: i e = insere o elemento e; n = calcula o número de elementos */
			if (op[0] == 'i') {
				scanf("%d", &e); Insere(L,e);
			} else {
				printf("%d\n", NumeroElementos(L));
			}
		} else {
			/* teste automático */
			for (int i=1; i<=1000000; i++) {
				Insere(L,i);
			}	
			printf("%d\n", NumeroElementos(L));
		}
	}

	return 0;
}