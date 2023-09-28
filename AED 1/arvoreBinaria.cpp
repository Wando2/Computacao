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
    int m; //  n de elementos na arvore
};

void Constroi(Arvore& T, int m) {
    T.Raiz = NULL;
    T.m = m;
}


int busca (No * &t, No ** &posIns,int chave,char &flag){
    
        posIns = &(t);
        
        if (t == NULL){
            return -999;
        }
    
        if (t->chave == chave){
            flag = 'F';
            return t->chave;
           
        }

        else if (t->chave > chave) {
           flag = 'e';
           return busca(t->Esq,posIns,chave,flag);
            
        }
        
        else {
            flag= 'd';
            return busca(t->Dir,posIns,chave,flag);

            
            
        }

    

    
}

void insere(Arvore &t,int c,int x){
    No ** posIns;
    char flag;
    int v = busca(t.Raiz,posIns,c,flag);

 
    

    if (v == -999){
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
