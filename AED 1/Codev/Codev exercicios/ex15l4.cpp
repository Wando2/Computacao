#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

void remove(No * &L){
        No * p = L;
        L = L->Prox;
        free(p);
}



void RemoveMaiores(No * &L, int k) {
   if (L == NULL) {
        return;
    }



    else {
     
        RemoveMaiores(L->Prox,k);

        if (L->E > k){
            remove(L);
        }

    }
}