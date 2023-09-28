#include <stdio.h>
#include "verinput.h"



void insereVetor(int n, float vetor[], FILE * Arquivo){

    for(int i = 0; i < n; i++){
        fscanf(Arquivo,"%f",&vetor[i]);

    }

}

int lerArquivo(FILE * vetor1Arq, FILE * vetor2Arq,float vetor1[], float vetor2[]){
int n1, n2;

// le a primeira linha
fscanf(vetor1Arq,"%d",&n1);
fscanf(vetor2Arq,"%d",&n2);




if (n1 != n2){
    printf("Erro: os vetores possuem comprimentos distintos\n");
    return -1;
}

insereVetor(n1,vetor1,vetor1Arq);

insereVetor(n2,vetor2,vetor2Arq);


return n1;

}