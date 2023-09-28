#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct No {
	int E;
	int h;
	No * Esq;
	No * Dir;
} No;

int comparar(int x, int y){
    if(x > y){
		return x;
	}

	else {
		return y;
	}
}

int zapzap(No * T){
    if (T == NULL){
        return 0;         
    }

   int leftheight = zapzap(T->Esq);
    int rightheight = zapzap(T->Dir);
  
  return T->h = comparar(leftheight,rightheight) +1 ;
    
   

}


void AtualizaAltura(No * T) {
	
   
    zapzap(T);

}
