#include <stdio.h>
#include <stdbool.h>


  bool busca (int L[], int N, int X);
  void insere (int *L,int *N,int X);
  void remover (int *L, int *N,int X);
      
    bool busca (int L[], int N,int X) {
        for (int i = 1; i <= N; i++){
            if (L[i] == X) { return true;}}
        return false;
    }
    
    void insere (int *L,int *N, int X){
        L[*N+1] = X;
        *N += 1;
    }
    
    
    void remover (int *L, int *N, int X){
        for (int i = 1; i <= *N; i++){
            if (L[i] == X){
                L[i] = *N;
                *N -= 1;
                
            }
        }
    }

    int main() {
        int L[7]; int N = 0;
      
        insere(L,&N,9);
        insere(L,&N,3);
        insere(L,&N,2);
        insere(L,&N,1);
        insere(L,&N,77);
        insere(L,&N,17);
        insere(L,&N,4);
       
        remover(L,&N,9);
      
        
        for(int i=1; i<=N;i++){
             printf("%d  ",L[i]);
             
        }
        
    
        
    
        return 0;
    }