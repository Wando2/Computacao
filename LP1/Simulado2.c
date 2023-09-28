#include <stdio.h>
#include <string.h>
#define MAX_SIZE 999999

int obterChaves(FILE * arq1,FILE * arq2, FILE * saida){
   int contagem = 0;
   int linha1, linha2;

   while(fscanf(arq1,"%d",&linha1) == 1){

    rewind(arq2);

        while(fscanf(arq2,"%d",&linha2) == 1){ // le uma linha de um arquivo de acordo com o formato especificado e guarda numa variavel
            if (linha1 == linha2){
                fprintf(saida, "%d",linha1); // escreve o valor de uma variavel em um arquivo com o formato especificado
                contagem++;
                break;
            }
        }
   }

return contagem;


}


int main(){
    FILE * arq1, * arq2, * saida;
    arq1 = fopen("arq1.txt", "r");
    arq2 = fopen("arq2.txt", "r");
    saida = fopen("saida.txt", "w");

    if(arq1 == NULL || arq2 == NULL || saida == NULL){
        printf("nao foi possivel ler algum dos arquivos");
        return 0;
    }


    printf("o numero de chave iguais e %d",obterChaves(arq1,arq2,saida));



}