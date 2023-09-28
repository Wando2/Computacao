#include <stdio.h>
#include <string.h>



int main(){
char nomeArquivo[100];
FILE * arquivo;

int carImprimivel = 0, carNao = 0,total = 0, stop = 0;


scanf("%s",nomeArquivo);

arquivo = fopen(nomeArquivo,"r");

if (arquivo == NULL){
    printf("Erro no arquivo %s\n",nomeArquivo);
    return 0;
}

while (stop != 1){
    char c;
    c = getc(arquivo);

    if (c ==  '\n')
    {
        carNao++;
    }

    else if(c == EOF){
        stop =  1;
        
    }

    else {
        carImprimivel++;
    }
    
    

    

}

total = carImprimivel + carNao;

printf("%d\n%d\n%d\n",total,carImprimivel,carNao);

}


