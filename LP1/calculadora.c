#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void insiraTexto(char* valores1) {
    printf("Insira o texto1: ");
    fgets(valores1, 100, stdin);
   
   
}

void conversao(char * valores1, double * V1Conver, double * V2Conver, char *operador){
    int i = 0;
    char V1Aux[20];
    char V2Aux[20];
    
    while(valores1[i] != '+' && valores1[i] != '-' && valores1[i] != '*' && valores1[i] != '/'){
        i++;
    }

    * operador = valores1[i];
   
    

// V1
   for (int j = 0; j < i; j++){
        V1Aux[j] = valores1[j];
   }

// final da string aux

 V1Aux[i] = '\0';

 // v2
  int k = 0;
  int L = i + 1;
  for (L ; valores1[L] != '\0'; L++){
    V2Aux[k++] = valores1[L];
    ;
  }

// final da string

 V2Aux[k-1] = '\0';



//conversao de string para double

* V1Conver = atof(V1Aux);
    
* V2Conver = atof(V2Aux);


}


double operacao(double V1Convertido, char operador, double V2Convertido){
   double resultado;

    switch (operador)
    {
    case '+':
    resultado = V1Convertido + V2Convertido;
        break;
    
    case '-':
    resultado = V1Convertido - V2Convertido;
        break;


    case '*':
    resultado = V1Convertido * V2Convertido;
        break;

    case '/':
    resultado = V1Convertido / V2Convertido;
        break;
    
    
    default:
        break;
    }

    return resultado;
}



int main(){
    char valores1[100];
    double V1Convertido;
    double V2Convertido;
    char operador;
   
    insiraTexto(valores1);

    conversao(valores1,&V1Convertido,&V2Convertido,&operador);

    printf("%2f",operacao(V1Convertido,operador,V2Convertido));
  

    return 0;
}