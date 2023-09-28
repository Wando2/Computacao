#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int Kultimate(No * L,int k,int &n){
    int x;

  if (L->Prox != NULL){
     return x = Kultimate(L->Prox,k,n);
    }
    n++;

    if (k > n){
        return -1;
    }

    else if (k = n){
        return L->E;
    }

     if (k > n){
        return x;
    }

  } 

int KUltimo(No * L, int k) {
	int n = 0;
   return Kultimate(L,k,n);
}
