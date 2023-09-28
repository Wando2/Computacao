#include <stdio.h>
#include <stdbool.h>


int fibonacci(int n){ // fibonaci sem memorizao

if ( n == 1 || n == 2 ){
    return 1;
}

else {
    return fibonacci(n-1) + fibonacci(n-2);
}}


int Valores[100];


int fibonaciMemo(int n){

    if(Valores[n] == -1){

        if(n == 1 || n == 2){
            Valores[n] == 1;
           
        }

        else {
            Valores[n] = fibonaciMemo(n-1) + fibonaciMemo(n-2);
        }
   }

   
    return Valores[n];


}


int main(){

int numeroFib = 11;

for (int i = 1; i <= numeroFib; i++) {
    Valores[i] = -1; // Inicializa todos os elementos de Valores com -1
}
                                                                                                                                                                                                             
fibonaciMemo(numeroFib);

printf("o numero de fibonaci e %d \n",fibonacci(numeroFib));

printf("o numero de fibonaci com memorizazao e %d \n",fibonaciMemo(numeroFib));



}