#include <stdio.h>
#include <stdlib.h>

int Impar(int n) {
	if(n == 0) {
        return 0;}

    else if (n == 1){
        return 1; 
    }

    else {
        return Impar(n-1) + 2;
    }
    
}
