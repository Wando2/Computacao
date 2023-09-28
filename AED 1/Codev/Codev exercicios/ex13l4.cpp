#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int Ultimo(No * L) {
	if (L == NULL){
        return -1;
    }

    else if (L->Prox != NULL){
        Ultimo(L->Prox);
    }

    else {
        return L->E;
    }

}
