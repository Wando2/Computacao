#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;



No * InverteAux(No * L,No *&pUlt) {
	

    


    

    


}



No * Inverte(No * L) {
	if ( L == NULL || L->Prox == NULL){
        return L;
    }

    No * Head = Inverte(L->Prox);
    
    L->Prox->Prox = L;
    L->Prox = NULL;


    return Head;
    

    


}
