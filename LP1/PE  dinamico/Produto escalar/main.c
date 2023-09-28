#include <stdio.h>
#include <stdlib.h>
#include "verinput.h"
#include "escalar.h"

int main() {
    char nomeArquivo[100];
    char nomeArquivo2[100];

    scanf("%s", nomeArquivo);
    scanf("%s", nomeArquivo2);

    FILE* vetor1Arq = fopen(nomeArquivo, "r");
    FILE* vetor2Arq = fopen(nomeArquivo2, "r");

    if (vetor1Arq == NULL) {
        printf("Erro: arquivo do vetor 1 não foi encontrado\n");
        return 1;
    }

    if (vetor2Arq == NULL) {
        printf("Erro: arquivo do vetor 2 não foi encontrado\n");
        fclose(vetor1Arq);
        return 1;
    }

    int n1, n2;

    fscanf(vetor1Arq, "%d", &n1);
    fscanf(vetor2Arq, "%d", &n2);

    if (n1 != n2) {
        printf("Erro: os vetores possuem comprimentos distintos\n");
        fclose(vetor1Arq);
        fclose(vetor2Arq);
        return 1;
    }

    float* vetor1 = (float*)malloc(n1 * sizeof(float));
    float* vetor2 = (float*)malloc(n2 * sizeof(float));

    if (vetor1 == NULL || vetor2 == NULL) {
        printf("Erro: falha na alocação de memória\n");
        fclose(vetor1Arq);
        fclose(vetor2Arq);
        free(vetor1);
        free(vetor2);
        return 1;
    }

    for (int i = 0; i < n1; i++) {
        fscanf(vetor1Arq, "%f", &vetor1[i]);
    }

    for (int i = 0; i < n2; i++) {
        fscanf(vetor2Arq, "%f", &vetor2[i]);
    }

    float resultado = produtoEscalarRecursivo(vetor1, vetor2, n1);
    printf("%.3f\n", resultado);

    fclose(vetor1Arq);
    fclose(vetor2Arq);
    free(vetor1);
    free(vetor2);

    return 0;
}
