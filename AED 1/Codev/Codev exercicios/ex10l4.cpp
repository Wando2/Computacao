

void removeAuxiliar(int L[],int &n,int k,int i){
   if (i == -1){
        return;
   }

    else if (n == 0){
        return;
    }
    
  else if (i == -10){
        i = n-1;
    }

    if (L[i] > k){
        L[i] = L[n-1];
        n--;
       
    }
   
     return removeAuxiliar(L,n,k,i-1);
}


void RemoveMaiores(int L[], int &n, int k) {
	removeAuxiliar(L,n,k,-10);
}