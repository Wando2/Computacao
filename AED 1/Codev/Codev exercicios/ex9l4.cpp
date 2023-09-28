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

