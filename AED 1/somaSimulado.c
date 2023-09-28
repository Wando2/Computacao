#include <stdio.h>

double SomaRec(double arr[], int n){
double soma = 0;

if (n == 0){
    soma = arr[0];
    return soma;
}

else{
    return SomaRec(arr,n-1) + arr[n];
}

}


int main (void)
{
double Vet []={1.0, 2.0, 3.0, 4.0, 5.0};
printf("O somatório é igual a %f", SomaRec(Vet, 5) );
}


