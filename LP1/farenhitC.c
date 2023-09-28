#include <stdio.h>
#include <float.h>


float GrauParaFahrenheit(float Graus){
    float Fahrenheit = (Graus *1.8) + 32;
    
    return Fahrenheit;
}

int main () {
    float Celsius, intervalo, elementos;

    printf("Insira um numero inicial em graus para converter em Fahrenheit: ");
    scanf("%f",&Celsius);

    
     printf("Digite o valor final da tabela ");
    scanf("%f",&elementos);

    printf("Digite o incremento dos valores em grau ");
    scanf("%f",&intervalo);


    


    for (Celsius; Celsius <= elementos; Celsius += intervalo){
    printf("A conversao de %.2f Graus Celsius para Fahrenheit e %.2f\n",Celsius, GrauParaFahrenheit(Celsius));

}

}