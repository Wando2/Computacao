#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct contato {
    int numero;

};

int main(){

    contato * p1; 
    p1 = (contato *)malloc(sizeof(contato));
    p1->numero = 8232;

    
    contato * p2;
    p2 = (contato *)malloc(sizeof(contato));
    p2->numero = 3214;


contato * array[10];

array[0] = p1;


}

