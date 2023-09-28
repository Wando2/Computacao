#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindromo(char palavra[]){
    size_t length = strlen(palavra);
    int posicaoDeTras = length -2;

    
    for (int i = 0; i <= posicaoDeTras; i++, posicaoDeTras -= 1){
         
            if (palavra[i] != palavra[posicaoDeTras]){
                return false;
            } 
            
            
         
    }

    return true;
}


int main() {
    char tamanho[40];

    printf("insira uma palavra para realizar o teste do PALINDROMO\n");

    fgets(tamanho,sizeof(tamanho), stdin);

    printf(" A palavra %s e um palindromo? %s",tamanho, palindromo(tamanho) ? "true" : "false");
   

    return 0;


}