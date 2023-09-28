#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char * conversao(char base8[]){
    size_t length = strlen(base8);
    
   // char * base8para2 =calloc((length + 1) * 3, sizeof(char));
   char * base8para2 = malloc( ((length) * 3 + 1) * sizeof(char));
   base8para2[0] = '\0';

    char zerob2[4] = "000";
    char umb2[4] = "001";
    char doisb2[4] = "010";
    char tresb2[4] = "011";
    char quatrob2[4] = "100";
    char cincob2[4] = "101";
    char seisb2[4] = "110";
    char seteb2[4] = "111";

    for (int i = 0; i < length; i++){
       
       if (i == 0) {
            switch (base8[i])
            {
            case '1':
                char um0b2[2] = "1";
                strcat(base8para2, um0b2);
                break;

            case '2':
               char dois0b2[3] = "10";
                strcat(base8para2, dois0b2);
                break;

                case '3':
                char tres0b2[3] = "11";
                strcat(base8para2, tres0b2);
                break;   

            default:
                break;
            }

             if (base8[i] == '4') {
                strcat(base8para2, quatrob2);
            }
            else if (base8[i] == '5') {
                strcat( base8para2, cincob2);
            }
            else if (base8[i] == '6') {
                strcat(base8para2, seisb2);
            }
            else if (base8[i] == '7') {
                strcat(base8para2, seteb2);
            }
       }
       
        if(i != 0) {
            if (base8[i] == '0') {
                strcat(base8para2, zerob2);
            }
            else if (base8[i] == '1') {
                strcat(base8para2, umb2);
            }
            else if (base8[i] == '2') {
                strcat(base8para2, doisb2);
            }
            else if (base8[i] == '3') {
                strcat(base8para2, tresb2);
            }
            else if (base8[i] == '4') {
                strcat(base8para2, quatrob2);
            }
            else if (base8[i] == '5') {
                strcat( base8para2, cincob2);
            }
            else if (base8[i] == '6') {
                strcat(base8para2, seisb2);
            }
            else if (base8[i] == '7') {
                strcat(base8para2, seteb2);
            }
    }

    }

    return base8para2;
}

int main(){
    char base8[9];
    
    printf("insira o numero na base 8 \n");

    fgets(base8,sizeof(base8),stdin);

   
    printf("numero em base 2: %s\n", conversao(base8));




}