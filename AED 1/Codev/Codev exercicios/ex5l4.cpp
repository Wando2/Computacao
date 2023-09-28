#include <stdio.h>
#include <stdlib.h>




int RaizQuad(int n) {
    
    if (n == 0){
        return 0;
    }

    else if (n == 1){
        return 1;
    }
    
    int x = RaizQuad(n-1); 

    if((x+1) * (x+1) > n){
        return x;
    }

    else {
        return x + 1;
    }
    

}




// assume n >= 0
	// retorna r tal que r^2 <= n < (r+1)^2
	/* insert your code here */