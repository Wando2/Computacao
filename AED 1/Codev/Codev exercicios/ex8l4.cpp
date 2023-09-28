#include <stdio.h>
#include <stdlib.h>

bool palindran(char C[],int i,int n){

int j = n-1;

if (i >= j){
    return true;
}

if (C[i] == C[j]){
    return palindran(C,i+1,j);
}

else {
    return false;
}





}

bool EhPalindromo(char C[], int n) {

return palindran(C,0,n);

}

