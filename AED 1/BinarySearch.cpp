#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int colecao[100];
int n = 0;

int insere(int arr[], int &n, int x){
   int i = 0;
   while (i < n && arr[i] < x){
    i++;
   }

   if ( n != 0){

    int j = n;

    while(j > i){
        arr[j] = arr[j-1];
        j--;
    }

 
    
   }

    arr[i] = x;

    n++;


   return 0;
}

int buscaBinaria(int arr[], int n, int x){
    // o algoritimo consite em dividir o incio e fim do vetor para achar a metade.
    // caso a metade não seja igual ao valor buscado, nos conferimos se essa metade é maior ou menor que o valor
    // se a metade for maior, então nos definimos o novo final como a metade, pois não adianta buscar o valor além dessa metade, uma vez que ele é menor
    // o mesmo vale para o inverso. caso a metade seja menor, não adianta procurar no intervalo anterior a essa metade
    // o algoritimo se repete até encontrar o valor ou o inicio ser igual o fim.
    int inicio = 0;
    int fim = n - 1;
    int metade = (inicio + fim) / 2;

    while (inicio < fim){

        if (arr[metade] == x){
            return 1;
        }

        else if (metade > x) {
            fim = metade -= 1;

        }

        else {
            inicio = metade +=1;
        }

        
    }

    return -1;
    
}

void primtar(int arr[],int n){
    for(int i = 0 ; i < n; i++){
        printf("cala boca puta n. %d \n",arr[i]);
    }
}

int main(){
    
    insere(colecao,n,10);
     insere(colecao,n,5);
      insere(colecao,n,4);
       insere(colecao,n,33);
        insere(colecao,n,22);
         insere(colecao,n,12);
          insere(colecao,n,3);
           insere(colecao,n,80);

           primtar(colecao,n);
          printf("%d",buscaBinaria(colecao,n,12));
           printf("%d",buscaBinaria(colecao,n,33));
            printf("%d",buscaBinaria(colecao,n,42));
           

}