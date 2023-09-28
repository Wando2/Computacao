#include <stdio.h>
#include <stdlib.h>


typedef struct No {
	int somaChaveD;
    int altura;
    int nivel;
    int somachaveD2;
    int SomachaveA;
    int SomachaveA2;
    int Pnivel;
	No * Esq;
	No * Dir;
    int chave;
} No;


struct Arvore {
    No* Raiz;
    int m;
};

void Constroi(Arvore& T, int m) {
    T.Raiz = NULL;
    T.m = m;
}

void Insere(struct Arvore* T, int chave) {
    // Cria um novo nó
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->chave = chave;
    novoNo->Esq = NULL;
    novoNo->Dir = NULL;

    // Caso a árvore esteja vazia, o novo nó será a raiz
    if (T->Raiz == NULL) {
        T->Raiz = novoNo;
        return;
    }

    // Encontra a posição correta para inserir o novo nó
    struct No* atual = T->Raiz;
    struct No* pai = NULL;
    while (1) {
        pai = atual;

        // Verifica se a chave já existe na árvore
        if (chave == atual->chave) {
            printf("Chave duplicada. A inserção não é permitida.\n");
            free(novoNo);
            return;
        }

        // Decide se o novo nó deve ser inserido à esquerda ou à direita
        if (chave < atual->chave) {
            atual = atual->Esq;
            if (atual == NULL) {
                pai->Esq = novoNo;
                return;
            }
        } else {
            atual = atual->Dir;
            if (atual == NULL) {
                pai->Dir = novoNo;
                return;
            }
        }
    }
}

int comparar(int x, int y){
    if(x > y){
		return x;
	}

	else {
		return y;
	}

}
int alturaP(No *&T){
    if (T != NULL){

        int he = alturaP(T->Esq);
        int hd = alturaP(T->Dir);

        return T->altura = comparar(he,hd) + 1;

    }
    else {
        return 0;
    }
}

void nivelP(No *&t,int incremento){
    if (t != NULL){
         nivelP(t->Esq,incremento+1);
        nivelP(t->Dir,incremento+1);

        t->nivel = 1 + incremento;

    }
   

}

int somachaveD(No *&t){
    if (t == NULL){
        return 0;
    }
    else {
        int de = somachaveD(t->Esq);
        int dd = somachaveD(t->Dir);

        return t->somaChaveD = de + dd + t->chave;
    }
}

int somachaveD2(No *&t){

    
    if (t == NULL){
        return 0;
    }
    else {
        int de = somachaveD2(t->Esq);
        int dd = somachaveD2(t->Dir);

       t->somachaveD2 = de + dd;

        return de + dd + t->chave;
    }
}

int somaDescendente(No *&t,int incremento){
    if(t == NULL){
        return 0;
    }

    else {
        somaDescendente(t->Esq,incremento+t->chave);
        somaDescendente(t->Dir,incremento+t->chave);

        return t->SomachaveA = t->chave + incremento;
    }
    
}

int somaDescendente2(No *&t,int incremento){
    if(t == NULL){
        return 0;
    }

    else {
        somaDescendente2(t->Esq,incremento+t->chave);
        somaDescendente2(t->Dir,incremento+t->chave);

        return t->SomachaveA2 = incremento;
    }
    
}



void porcentagemNivelAuxiliar(No *&t,int nivel,int arr[]){
    if (t == NULL)
    {
        return;
    }
    else {
        porcentagemNivelAuxiliar(t->Esq,nivel+1,arr);
        porcentagemNivelAuxiliar(t->Dir,nivel+1,arr);

        arr[nivel] += t->chave;
        t->Pnivel = (t->chave * 100) / arr[nivel];
    }
}

void porcentagemNivel(No *&t){
int arr[6] = {0};


porcentagemNivelAuxiliar(t,1,arr);

for (int i = 1; i < 6; i++){
    printf("%d   ",arr[i]);
}

}


int main() {
    struct Arvore minhaArvore;
    Constroi(minhaArvore, 10);  // Cria uma árvore com m = 10
    Insere(&minhaArvore, 5);     
    Insere(&minhaArvore, 10);    // Insere o nó com chave 10
    Insere(&minhaArvore, 7);     // Insere o nó com chave 7
    Insere(&minhaArvore, 3);     
    Insere(&minhaArvore, 11);    // Insere o nó com chave 10
    Insere(&minhaArvore, 9);     // Insere o nó com chave 7
    Insere(&minhaArvore, 19);     
    Insere(&minhaArvore, 21);   
    Insere(&minhaArvore, 17);
    // Funcoes
    
    alturaP(minhaArvore.Raiz);
    nivelP(minhaArvore.Raiz,0);
    somachaveD(minhaArvore.Raiz);
    somachaveD2(minhaArvore.Raiz);
    somaDescendente(minhaArvore.Raiz,0);
    somaDescendente2(minhaArvore.Raiz,0);
    porcentagemNivel(minhaArvore.Raiz);

}