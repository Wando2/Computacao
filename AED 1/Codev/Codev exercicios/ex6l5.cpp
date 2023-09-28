#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct No {
	int E;
	int niv;
	No * Esq;
	No * Dir;
} No;

int comparar(int x, int y){
    if(x > y){
		return x;
	}

	else {
		return y;
	}
}

void AtualizeSeuZap(No * T,int incremento){
    if (T == NULL){
        return;
    }
    
    else {
     AtualizeSeuZap(T->Esq,incremento+1);
     AtualizeSeuZap(T->Dir,incremento+1);

    T->niv = 1 + incremento;
    }

    

}


void AtualizaNivel(No * T) {

AtualizeSeuZap(T,0);
  

}
