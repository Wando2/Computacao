#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FUNCIONARIOS 10
#define MAX_NOME 51
#define MAX_MATRICULA 13
#define MAX_ENDERECO 66
#define MAX_CPF 12
#define MAX_COD_BANCO 4
#define MAX_AGENCIA 6
#define MAX_CONTA 9

typedef struct {
    char nome[MAX_NOME];
    char matricula[MAX_MATRICULA];
    char endereco [MAX_ENDERECO];
    char cpf[MAX_CPF];
    char cod_banco[MAX_COD_BANCO];
    char agencia[MAX_AGENCIA];
    char conta[MAX_CONTA];
    float valor_hora;
    float salario_mes;

} Funcionario;

typedef struct{
    char matricula[MAX_MATRICULA];
    float horasTrab;


    

}horasMensais;

void carregarHorarios(horasMensais horas[]){
FILE * ArqHoras = fopen("novembro.txt","r");
char str[10];

for(int i = 0; i < 10; i++){
    fgets(horas[i].matricula,13,ArqHoras); getc(ArqHoras);
    fgets(str,10,ArqHoras);
    horas[i].horasTrab = atof(str);

}

 fclose(ArqHoras);

}

void carregaFuncionarios(Funcionario funcionarios[],FILE * ArqFuncionarios){
char str[10];
for(int i = 0; i < MAX_FUNCIONARIOS; i++){
    fgets(funcionarios[i].nome,MAX_NOME,ArqFuncionarios); getc(ArqFuncionarios);
    fgets(funcionarios[i].matricula,MAX_MATRICULA,ArqFuncionarios); getc(ArqFuncionarios);
    fgets(funcionarios[i].endereco,MAX_ENDERECO,ArqFuncionarios); getc(ArqFuncionarios);
    fgets(funcionarios[i].cpf,MAX_CPF,ArqFuncionarios); getc(ArqFuncionarios);
    fgets(funcionarios[i].cod_banco,MAX_COD_BANCO,ArqFuncionarios); getc(ArqFuncionarios);
    fgets(funcionarios[i].agencia,MAX_AGENCIA,ArqFuncionarios); getc(ArqFuncionarios);
    fgets(funcionarios[i].conta,MAX_CONTA,ArqFuncionarios); getc(ArqFuncionarios);

    fgets(str,sizeof(str),ArqFuncionarios);
    
    funcionarios[i].valor_hora = atof(str);
    
    

}


}

int compareFuncionarios(const void* a, const void* b) {
    Funcionario* funcA = (Funcionario*)a;
    Funcionario* funcB = (Funcionario*)b;

    return strcmp(funcA->nome, funcB->nome);
}
void atribuirSalario(Funcionario funcionarios[],horasMensais horasFuncionarios[]){
    
    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10; j++){
           

            if(strcmp(funcionarios[i].matricula,horasFuncionarios[j].matricula) == 0) {
                funcionarios[i].salario_mes = (funcionarios[i].valor_hora * horasFuncionarios[j].horasTrab);
            }

        }

    }

}


int main(){
Funcionario funcionarios[MAX_FUNCIONARIOS];
horasMensais horasFuncionarios[MAX_FUNCIONARIOS];

FILE * ArqFuncionarios = fopen("funcionarios.txt","r");
FILE * FolhaPagamento = fopen("folha.txt","w");

carregaFuncionarios(funcionarios,ArqFuncionarios);
 fclose(ArqFuncionarios);

 carregarHorarios(horasFuncionarios);

 atribuirSalario(funcionarios,horasFuncionarios);

  qsort(funcionarios, MAX_FUNCIONARIOS, sizeof(Funcionario), compareFuncionarios);



     for (int i = 0; i < 10; i++) {
        printf("%s|%s|%s|%s|%s|%.2f\n", funcionarios[i].nome, funcionarios[i].cpf, funcionarios[i].cod_banco, funcionarios[i].agencia, funcionarios[i].conta, funcionarios[i].salario_mes);
        fprintf(FolhaPagamento,"%s|%s|%s|%s|%s|%.2f\n", funcionarios[i].nome, funcionarios[i].cpf, funcionarios[i].cod_banco, funcionarios[i].agencia, funcionarios[i].conta, funcionarios[i].salario_mes);
        
    }



}