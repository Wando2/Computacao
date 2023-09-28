#include <stdio.h>
#include <stdlib.h>

int Exp(int b, int n) {
	if (n == 0){
        return 1;
    }

    else if(n == 1){
        return b;
    }

    else if ( n%2 == 0){
        int x = Exp(b,n/2);
        return x * x;
    }

    else {
        int x = Exp(b,(n-1)/2);
        return (x*x) * b;
    }



   
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int b; int n; 
	while (scanf("%d %d", &b, &n)>0) {
		if (b>=0) {
			/* teste manual */
			printf("%d\n", Exp(b,n));
		} else {
			/* teste automático */
			b = 1; n = 50000;
			for (int t=1; t<=200; t++) Exp(b,n);
			printf("%d\n", Exp(b,n));
		}
	}

	return 0;
}