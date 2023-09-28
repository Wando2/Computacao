#include <stdio.h>
#include <string.h>
#define MAX_SIZE 999999

int obterChaves(FILE * arquivo,int chaves[]){
    char linha[8];
    int contagem = 0;

    while(fgets(linha,8,arquivo) != NULL){
        chaves[contagem++] = atoi(linha);
    }

    return contagem;

}

int validarChaves(FILE * saida,int chaves1[],int chaves2[], int contagem1,int contagem2){
    int i, j = 0;

    while(i < contagem1 && j < contagem2){

    
    }



}

int main(){
    FILE * arq1, * arq2, * saida;
    arq1 = fopen("arq1.txt", "r");
    arq2 = fopen("arq2.txt", "r");
    saida = fopen("saida.txt", "w");

    int chaves1[MAX_SIZE], chaves2[MAX_SIZE], chavesValidas[MAX_SIZE], contagem1,contagem2,contagemTotal;



}