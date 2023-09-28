#include <stdio.h>
#include "verinput.h"
#include "escalar.h"

void imprimirVetor(float vetor[], int n) {
    printf("Elementos do vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%.3f ", vetor[i]);
    }
    printf("\n");
}

int main() {


    
    FILE* vetor1Arq = fopen("vetor1.txt", "r");
    FILE* vetor2Arq = fopen("vetor2.txt", "r");

    if (vetor1Arq == NULL) {
        printf("Erro: arquivo do vetor 1 não foi encontrado\n");
        return 1;
    }

    if (vetor2Arq == NULL) {
        printf("Erro: arquivo do vetor 2 não foi encontrado\n");
        fclose(vetor1Arq);
        return 1;
    }

     // Tamanho máximo dos vetores
    float vetor1[50];
    float vetor2[50];

    

    int numElementos = lerArquivo(vetor1Arq, vetor2Arq, vetor1, vetor2);

    if (numElementos == -1) {
        fclose(vetor1Arq);
        fclose(vetor2Arq);
        return 1;
    }

    imprimirVetor(vetor1,numElementos);

    float resultado = produtoEscalarRecursivo(vetor1, vetor2, numElementos);
    printf("Produto escalar: %.3f\n", resultado);

    fclose(vetor1Arq);
    fclose(vetor2Arq);

    return 0;
}
