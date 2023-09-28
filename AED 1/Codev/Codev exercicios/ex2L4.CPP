#include <stdio.h>
#include <stdlib.h>

int Exp(int b, int n) {
	if (n == 0){
        return 1;
    }

    else {
        return Exp(b,n-1) * b;
    }
}