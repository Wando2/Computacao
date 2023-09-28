#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct no {
    int e;
    struct no *prox;
};

void insere (no **l, int x){
no *novo;
novo = (no *) malloc(sizeof(no));
novo->e = x;
novo->prox = *l;
*l = novo;

}

bool busca(no *l,int x) {
    no *p = l;

    while(p != NULL && p->e != x){
        p = p->prox;
    }

   return (p != NULL);
   
}

void remove(no **l,int x){
    no *p = *l;
    no *pAnt = NULL;
    

    while( p != NULL && p->e != x){
       pAnt = p;
        p = p->prox;
        

    }

    if (p != NULL){
    
            if (pAnt != NULL) {
                pAnt->prox = p->prox;
            }

            else{
                *l = p->prox;
            }

            free(p);
        }
    
    else { 
       printf("valor não encontrado para removoção");
       
    }
    

}

int main (){

no *l = NULL;

insere(&l,4);
insere(&l,6);
insere(&l,9);
insere(&l,10);

printf("o resultado da busca e %s\n", busca(l,7) ? "true" : "false");
printf("o resultado da busca pre-remover %s\n", busca(l,4) ? "true" : "false");

remove(&l,4);

printf("o resultado da busca pos-remover %s\n", busca(l,4) ? "true" : "false");


return 0;


}