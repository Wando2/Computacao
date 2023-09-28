#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct No {
    No * prox;
    int e;
};

struct listaLinear {
    No * inicio = NULL;
    int n = 0;
};



void insere(listaLinear * &L, int x){
    No * novo = (No *) malloc(sizeof(No));
    novo->e = x, novo->prox = NULL;
    No * p = L->inicio;
    No * pAnt = NULL;

    if (p != NULL){

        while( p->e < x){
           pAnt = p;
            p = p->prox;
        }

        if (pAnt == NULL){
            novo->prox = p;
            L->inicio = novo;
        }

        else {
            pAnt->prox = novo;
            novo->prox = p;
        }

    } else {
        L->inicio = novo;
    }
    
    L->n += 1;

}

int binarySearch(listaLinear *L, int x){
    

}

void primtar(listaLinear *L){
    No * p = L->inicio;

  for (int i = 0; i < L->n; i++){
    printf("o valor do NO e %d \n",p->e);
   
    p = p->prox;
  }
     printf("o valor de N e %d \n",L->n);
    
}

int main(){

listaLinear * L;

insere(L, 4);
insere(L, 1);
insere(L, 7);
insere(L, 2);
insere(L, 9);

primtar(L);

}