#include <stdio.h>
#include <stdlib.h>

int Divisores(int n, int k) {
	 
    if (k == 0) {
        return 0;
    }
     
    else if (k == 1){
        return 1;
    }

    
    int x = Divisores(n,k-1);

   
     if (n%k == 0){
        return x+1;
    }

    else {
        return x;
    }

}