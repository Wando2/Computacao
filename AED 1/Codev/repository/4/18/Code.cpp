#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool DEBUG;

int Maximo(int A[], int n) {
    
    if( n == 1){
        return A[n-1];
    }

    int x = Maximo(A,n-1);

    if (A[n-1] > x){
        return A[n-1];
    }

    else {
        return x;
    }
}   



int main(int argc, char * argv[]) {
	setbuf(stdout, NULL); setbuf(stderr, NULL); DEBUG = (argc > 1);
	int n; int * A; 
	while (scanf("%d", &n)>0) {
		if (n>=0) {
			/* teste manual */
			A = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n; i++) scanf("%d", &A[i]);
			printf("%d\n", Maximo(A,n));
			free(A); 
		} else {
			/* teste automático */
			n = 50000; 
			A = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n/2; i++) A[i]=i;
			for (int i=n/2+1; i<n; i++) A[i]=n-i;
			for (int i=0; i<20; i++) Maximo(A,n);
			printf("%d\n", Maximo(A,n));
			free(A); 
		}
	}

	return 0;
}