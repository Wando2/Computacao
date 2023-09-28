#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct aluno {
    
    int idade;
};

struct turma{
    int turmaId;
    struct aluno * alunoNome;
    struct turma * prox;
};

void insere(turma * &L, aluno * novoAluno, int x) {
    turma * novaTurma;
    novaTurma = (turma *)malloc(sizeof(turma));
    novaTurma->alunoNome = novoAluno;
    novaTurma->prox = NULL;
    novaTurma->turmaId = x;
    turma *p = L;


    if(p == NULL) {
        L = novaTurma;
    } else {
        p->prox = novaTurma;
    }
    
}

int main() {

struct aluno leoPele {
    leoPele.idade = 10
};

struct aluno gabigol {
    gabigol.idade = 10
};

struct aluno negoney {
    negoney.idade = 10
};

turma *l = NULL;

insere(l,&gabigol,2);
insere(l,&gabigol,1);
insere(l,&leoPele,2);





}

