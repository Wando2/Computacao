#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

bool DEBUG;



void removeAuxiliar(int L[],int &n,int k,int i){
   if (i == -1){
        return;
   }

    else if (n == 0){
        return;
    }
    
  else if (i == -10){
        i = n-1;
    }

    if (L[i] > k){
        L[i] = L[n-1];
        n--;
       
    }
   
     return removeAuxiliar(L,n,k,i-1);
}


void RemoveMaiores(int L[], int &n, int k) {
	removeAuxiliar(L,n,k,-10);
}

void C_RemoveMaiores(int L[], int &n, int k) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	RemoveMaiores(L,n,k);
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
}

void Escreve(int L[], int n) {
	int * Lv = (int *) malloc(sizeof(int)*n);
	for (int i=0; i<n; i++) Lv[i] = L[i];
	sort(Lv,Lv+n);
	printf("["); for (int i=0; i<n; i++) printf("%d", Lv[i]); printf("]\n");
	free(Lv);
}

int main(int argc, char * argv[]) {
	setbuf(stdout, NULL); setbuf(stderr, NULL); DEBUG = (argc > 1); 
	int n; int * L; int k; 
	while (scanf("%d", &n)>0) {
		if (n!=-1) {
			/* n, e1, e2, ..., en, k */
			L = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n; i++) scanf("%d", &L[i]);	
			scanf("%d", &k);
			C_RemoveMaiores(L,n,k); Escreve(L,n); 
			free(L);
		} else {
			/* automatic test */
			int nlin = 50000; k = 2;
			n = nlin;
			L = (int *) malloc(sizeof(int)*n); 
			for (int t=1; t<=20; t++) {
				n = nlin;
				for (int i=0; i<n; i++) L[i] = (i%2==0 ? 2 : 3);
				C_RemoveMaiores(L,n,k); 
				if (t==1) Escreve(L,n); 
			}
			free(L);
		}
	}
	return 0;
}