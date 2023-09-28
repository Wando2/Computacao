#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int maxx(int x, int y){
    if (x > y) {
        return x;
    } else {return y;}
}

int Maior(No * L) {
	if (L == NULL){
        return -999999;
    }

    int maiorF = Maior(L->Prox);

    return maxx(maiorF,L->E);



}