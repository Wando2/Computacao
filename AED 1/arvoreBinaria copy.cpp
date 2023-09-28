#include <stdio.h>
#include <stdlib.h>


typedef struct No {
	int E;
	No * Esq;
	No * Dir;
    int chave;
} No;


struct Arvore {
    No* Raiz;
    int m;
};

void Constroi(Arvore& T, int m) {
    T.Raiz = NULL;
    T.m = m;
}


int busca (Arvore &t, No ** &posIns,int chave){
    No * q = t.Raiz;
    posIns = &(t.Raiz);

    while(q != NULL){
        if (q->chave == chave){
            return q->chave;
        }

        else if (q->chave > chave) {
            posIns = &(q->Esq);
            q = q->Esq;
            
        }
        
        else {
            posIns = &(q->Dir);
            q = q->Dir;
            
        }

    }

    return NULL;
}

void insere(Arvore &t,int c,int x){
    No ** posIns;
    int v = busca(t,posIns,c);

 
    

    if (v == NULL){
        No * Q = (No *) malloc(sizeof(No));
        Q->chave = c;
        Q->E = x;
        Q->Esq = NULL;
        Q->Dir = NULL;
        * posIns = Q;
    }

    else {
        printf("Chave já inserida porra");
    }
}

void insereArray(int arr[],Arvore &t,int n){
 

 for(int i = 0; i < n; i++){
    insere(t,arr[i],7);
 }

}

void pInOrdem(No * t){
    if (t != NULL){
        pInOrdem(t->Esq);
        printf("%d-",t->chave);
        pInOrdem(t->Dir);
    }

}


int main(){
     Arvore T;
    Constroi(T, 8);

    int arr[] = {5, 1, 9, 33, 11, 50, 100, 87, 21};
    int n = sizeof(arr) / sizeof(arr[0]);

    insereArray(arr,T,n);
    pInOrdem(T.Raiz);
  
  



 /*     insere(T, 10, 100);
     insere(T, 4, 100);
     insere(T,11,33);
     insere(T, 5, 50);
    insere(T, 15, 150);
    insere(T, 3, 30);
    insere(T, 7, 70);
    */

}               
