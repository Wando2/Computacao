#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int e;
    struct node *prox;
};

void insere(node **l, int x) {
    node *p = *l; // vai fazer a mesma funcao do L e ir passando de ponteiro em ponteiro
    node *pAnt = NULL; // guarda o valor do P anterior ao P atual, para que na inserção não tenha nos perdidos

    node *novo; // cria o no novo
    novo = novo = (node*) malloc(sizeof(node)); // aloca o no novo para ele não se perder
    novo->e = x; // guarda o elemento no nó novo
    novo->prox = NULL;

    if (p != NULL)  { // testa se o primeiro nó da cadeia é nulo (ainda sem nada). se for, ele atribui o L diretamente ao novo

        while(p != NULL && x > p->e){ // testa cada nó ate encontrar um nó com valor maior que x ou nulo
            pAnt = p; 
            p = p->prox; // guarda o ponteiro atual e avança para o proximo
        
        }

        if (pAnt == NULL) { // se o p anterior for nulo, significa que o novo nó tem que ser atribuido como primeiro
               novo->prox = p;
               *l = novo;
                
            } else {
               pAnt->prox = novo;
               novo->prox = p;
            } 

    } else {
        *l = novo;
    }

}

void remove(node **l,int x){
    node *p = *l;
    node *pAnt = NULL;

    while(p != NULL && p->e != x){
        pAnt = p;
        p = p->prox;
    }

    if (p != NULL) {
        if (pAnt == NULL){
            *l = p->prox;
        } else {
            pAnt->prox = p->prox;
        }

        free(p);
    }

}

bool busca(node *l,int x){
    node *p = l;

    while ( p != NULL && p->e != x ){
        p = p->prox;
    }
    
    return (p != NULL);
}

void printarNodes(node *l){
    node *p = l;
    int pos = 0;

    while (p != NULL)
    {
        printf("Node %d: %d\n", pos, p->e);
        pos++;
        p = p->prox;
    }
    
    
}

int main(){
    node *l = NULL;

    insere(&l, 10);
    insere(&l, 1);
    insere(&l, 3);
    insere(&l, 5);
    insere(&l, 2);
    insere(&l, 100);

    remove(&l,10);

   printf("Value %d %s found in the linked list.\n", 10, busca(l, 10) ? "was" : "was not");


    printarNodes(l);


}