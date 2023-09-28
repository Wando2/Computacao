
// <tipo> (*NomeDoapontador) (<tipoArg1>, ..., <tipoArgN>)
#include <stdio.h>
// fun() eh uma funcao normal com um parametro inteiro
// retornando void (nada)
void fun(int a)
{
    printf("O valor de a é: %d\n", a);
}

int multicanais(char op, int *a, int *b)
{

    switch (op)
    {
    case '+':
        return *a + *b;
        break;

    case '-':
        return *a - *b;

    default:
        break;
    }
}

int main(void)
{
    // fun_ptr é um apontador para uma funcao que tem um
    // parâmetro inteiro e retorna void
    void (*fun_ptr)(int);
    // atribui a fun_ptr o endereço da funcao fun()
    fun_ptr = &fun;
    // chama a funcao fun() usando o apontador fun_ptr
    (*fun_ptr)(10);

    int (*ptrMulticanais)(char, int *, int *);

    ptrMulticanais = &multicanais;

    int cu = 11;
    int tcheca = 13;
    char caldo = '+';

    int resultado = (*ptrMulticanais)(caldo, &cu, &tcheca);

    printf("o resultado é %d", resultado);
}