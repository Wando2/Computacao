#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int FIM_ENTRADA = -1000;
int ENTRADA_AUTOMATICA = -2000;

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;

int comp(int x,int y){
	if (x > y) {return x;}
	else {return y;}
}

int soma (No * T,int &s){
	if (T == NULL){
		s = 0;
		return 0;
	}
	int ME = -999999; int MD = -999999; int SE = 0; int SD = 0;
	
	if (T->Esq != NULL){
		ME = soma(T->Esq,SE);
	}
	
	if (T->Dir != NULL){
		MD = soma(T->Dir,SD);
	}
	
	
	
	s = SE + SD + T->E;
	
	return comp(comp(MD,ME),s);
	
	}



int MaiorSubarvore(No * T) {
	int xereca = 0;
	return soma(T,xereca);

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
		if (h>1) {
			T->E = -2;
		} else {
			T->E = 1; 
		} 
		PreencheCheia(T->Esq, h-1);
		PreencheCheia(T->Dir, h-1);
	}
}

void PreencheZigZag(No * &T, int h) {
	if (h==0) {
		T = NULL;
	} else {
		T = (No *) malloc(sizeof(No));
		if (h>1) {
			T->E = -2;
		} else {
			T->E = 1; 
		}
		PreencheZigZag(T->Esq, h-1);
		T->Dir = NULL;
	}
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	No * T = NULL; 
	int * e = (int *) malloc(sizeof(int) * 1000000); int n=0;
	while (scanf("%d", &e[n])>0) {
		if (e[n] > ENTRADA_AUTOMATICA) {
			/* teste manual: visita preordem de T (0 para nulo) */
			while (e[n] != FIM_ENTRADA) {
				n++;
				scanf("%d", &e[n]);
			}
			int i=0;
			Insere(T,e,i);
			printf("%d\n", MaiorSubarvore(T));
			Destroi(T);
			n=0;
		} else {
			/* teste automático */
			if (e[n] == ENTRADA_AUTOMATICA) {
				PreencheZigZag(T, 50000);
			} else {
				PreencheCheia(T, 19);
			}
			printf("%d\n", MaiorSubarvore(T));
			Destroi(T);
		}
	}
	free(e);
	return 0;
}