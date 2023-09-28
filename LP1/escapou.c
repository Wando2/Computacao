#include <stdio.h>
#include <string.h>

void insiraTexto(char sequence[]) {
    printf("Insira o texto: ");
    fgets(sequence, 100, stdin);
   
   
}

void converte(const char sequence[], char escapedSequence[]) {
    int i = 0;

   

    for (int j = 0; sequence[j] != '\0'; j++) {
        switch (sequence[j]) {
            case '\t':
                escapedSequence[i++] = '\\';
                escapedSequence[i++] = 't';
                break;

            case '\f':
                escapedSequence[i++] = '\\';
                escapedSequence[i++] = 'f';
                break;

            case '\v':
                escapedSequence[i++] = '\\';
                escapedSequence[i++] = 'v';
                break;

            case '\n':
                escapedSequence[i++] = '\\';
                escapedSequence[i++] = 'n';
                break;

            case '\r':
                escapedSequence[i++] = '\\';
                escapedSequence[i++] = 'r';
                break;

            default:
                escapedSequence[i++] = sequence[j];
                break;
        }
    }

   
}

void escreverNatela(char escaped[]){
    printf("Sequcia escapada: %s\n", escaped);

}


int main() {
    char sequence[100];
    char escapedSequence[200];
   

    insiraTexto(sequence);

    converte(sequence, escapedSequence);

    escreverNatela(escapedSequence);
   

    return 0;
}
