#include <stdio.h>
#include <stdbool.h>

int vetor[] = {10, 20, 30, 40, 50};

int ma(int n){

if ( n == 1){
    return vetor[n-1];
}


else {
    return (ma(n-1) * (n-1) + vetor[n -1]) / n;
}

}


int main(){
    

   int n = 5;

    printf("a media aritimetica e %d", ma(n));


}