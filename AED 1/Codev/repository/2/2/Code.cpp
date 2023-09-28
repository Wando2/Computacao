#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;


int Maior(No * L) {
	No *p = L;
    int maior = p->E;

    while (p != NULL){
      
      if (p->E > maior){
        maior = p->E;
      }

      p = p->Prox;
    }

    return maior;
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
			/* teste manual: i e = insere o elemento e; m = busca o maior */
			if (op[0] == 'i') {
				scanf("%d", &e); Insere(L,e);
			} else {
				printf("%d\n", Maior(L));
			}
		} else {
			/* teste automático */
			int n = 1000000;
			for (int i=n/2; i<=n; i++) {
				Insere(L,i);
			}	
			for (int i=1; i < n/2; i++) {
				Insere(L,i);
			}	
			printf("%d\n", Maior(L));
		}
	}
	return 0;
}