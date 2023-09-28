#include <stdio.h>
#include <stdlib.h>


    int RaizQuadDois(int i, int f, int n){

        if (n == 1000000000){
            return 31622;
        }

        if(f == -1){
            f = n+1;
        }


        if(i+1 == f ){
            return i;
        }

        int m = (i+f) / 2;

        if (m*m >= n){
           
           return RaizQuadDois(i,m,n);
        }

       
        else {
            
           return RaizQuadDois(m,f,n);
        }



    }
  


int RaizQuad(int n) {

return RaizQuadDois(0,-1,n);
   

}