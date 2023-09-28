#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;

int maxSports(int x, int y){
	if(x > y){
		return x;
	}

	else {
		return y;
	}
}

int Maior(No * T) {
	if (T == NULL){
		return 0;
	}

	else {
	int MaiorEsquerda = Maior(T->Esq);
	int Maiordireita = Maior(T->Dir);

	return maxSports(maxSports(Maiordireita,MaiorEsquerda),T->E);

	}

}

void Insere(No * &T, int e[], int &i) {
	if (e[i] == 0) {
		i++;
		T = NULL;
	} else  {
		T = (No *) malloc(sizeof(No));
		T->E = e[i]; i++;
		Insere(T->Esq, e, i);
		Insere(T->Dir, e, i);
	}
}

void Destroi(No * &T) {
	if (T != NULL) {
		Destroi(T->Esq);
		Destroi(T->Dir);
		free(T);
		T = NULL;
	}
}

void PreencheCheia(No * &T, int h) {
	if (h==0) {
		T = NULL;
	} else {
		T = (No *) malloc(sizeof(No));
		T->E = h;
		PreencheCheia(T->Esq, h-1);
		PreencheCheia(T->Dir, h-1);
	}
}

void PreencheZigZag(No * &T, int h) {
	if (h==0) {
		T = NULL;
	} else {
		T = (No *) malloc(sizeof(No));
		T->E = h;
		PreencheZigZag(T->Esq, h-1);
		T->Dir = NULL;
	}
}
