#include <stdio.h>
#include <stdlib.h>

typedef struct NoL {
	int E;
	NoL * Prox;
} NoL;

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;


NoL * elementosInternos(NoL * L, No * T){
   if (T == NULL){ // se o no não existem então a lista é vazia.
       return  L = NULL;
    }

     if (T->Esq != NULL){ // enquanto tiver subarvores 
         L = elementosInternos(L,T->Esq);
     }
    
    if (T->Dir != NULL){ 
        L = elementosInternos(L,T->Dir);

    }
    
    if (T->Esq != NULL || T->Dir != NULL){ // se tem pelo menos um filho
        NoL * Elm;
        Elm = (NoL *) malloc(sizeof(NoL));
        Elm->E = T->E;
        Elm->Prox = L;
        L = Elm;

        
    }

          
    return L; 
}


NoL * ListaNosInternos(No * T) {
    NoL * L;
    L = NULL;

    return elementosInternos(L,T);

}
