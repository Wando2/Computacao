#include <stdio.h>
#include <stdlib.h>

long long int Bin(int n, int k) {
	if ( k == 0){
        return 1;
    }

    else if (k == 1) {
        return n;
    }

    else {
        return Bin(n-1,k-1) * n  / k;
    }
}