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