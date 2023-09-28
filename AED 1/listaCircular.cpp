#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct No {
    int x;
    struct No * prox;
};

void insere(No * &L, No * &u, int x){
    No * novo;
    novo = (No *) malloc(sizeof(No));
    novo->x = x;
    if (L == NULL) {
        novo->prox = novo;
        L = novo;
    }

    else {
        novo->prox = u->prox;
        u->prox = novo;
       

    }
    
     u = novo;

}

void print_list(No * L) {
    if (L == NULL) {
        printf("List is empty\n");
        return;
    }

    No * current = L;
    do {
        printf("%d ", current->x);
        current = current->prox;
    } while (current != L);

    printf("\n");
}

int main(){
    No * L = NULL;
    No * u;

    insere(L,u,10);
     insere(L,u,4);
      insere(L,u,20);

       print_list(L);

}