#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int NumeroElementos(No * L) {
	if (L == NULL){
        return 0;
    }
    else {
        int n = NumeroElementos(L->Prox);
        return n + 1;
    }
}
