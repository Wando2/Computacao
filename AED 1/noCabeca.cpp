#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct no {
    int e;
    no * prox;
};

void insere(no *&l,int x){
    no * novo;
    novo = (no*) malloc(sizeof(no));
    novo->e = x;
    novo->prox = l->prox;
    l->prox = novo;
}

void printar(no *l){
    no * p = l->prox;
   
    while (p != NULL){
        printf("%d \n",p->e);
        p = p->prox;
    }
}

void remover(no *&l, int x){
    no *p = l;
    no * pAnt = NULL;

    while (p != NULL && p->e != x){
        pAnt = p;
        p = p->prox;
        
    }

    pAnt->prox = p->prox;

    free(p);

}


int main(){

no * cabeca;
cabeca = (no*) malloc(sizeof(no));
cabeca->e = 0;
cabeca->prox = NULL;

no * l = cabeca;

insere(l,3);
insere(l,2);
insere(l,8);
remover(l,8);

printar(l);

}