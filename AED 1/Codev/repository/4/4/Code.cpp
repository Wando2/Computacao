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

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; int k; 
	while (scanf("%d %d", &n, &k)>0) {
		if (n>=0) {
			/* teste manual */
			printf("%lld\n", Bin(n,k));
		} else {
			/* teste automático */
			n = 50000; k = 49999;
			for (int t=1; t<=200; t++) Bin(n,k);
			printf("%lld\n", Bin(n,k));
		}
	}

	return 0;
}