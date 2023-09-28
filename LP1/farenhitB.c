#include <stdio.h>


float GrauParaFahrenheit(float Graus){
    float Farenhit = (Graus *1.8) + 32;
    
    return Farenhit;
    
}

int main () {

float c1 = -10, c2 = 0, c3 = 10, c4 = 20, c5 = 30, c6 = 40, c7 = 50;


printf("A conversão de %.2f Graus Celsius para Fahrenheit é %.2f\n",c1, GrauParaFahrenheit(c1));

printf("A conversão de %.2f Graus Celsius para Fahrenheit é %.2f\n",c2, GrauParaFahrenheit(c2));

printf("A conversão de %.2f Graus Celsius para Fahrenheit é %.2f\n",c3, GrauParaFahrenheit(c3));

printf("A conversão de %.2f Graus Celsius para Fahrenheit é %.2f\n",c4, GrauParaFahrenheit(c4));

printf("A conversão de %.2f Graus Celsius para Fahrenheit é %.2f\n",c5, GrauParaFahrenheit(c5));

printf("A conversão de %.2f Graus Celsius para Fahrenheit é %.2f\n",c6, GrauParaFahrenheit(c6));

printf("A conversão de %.2f Graus Celsius para Fahrenheit é %.2f\n",c7, GrauParaFahrenheit(c7));



}