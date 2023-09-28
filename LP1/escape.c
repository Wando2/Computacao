#include <stdio.h>
#include <string.h>

void insiraTexto(char* sequence) {
    printf("Insira o texto: ");
    fgets(sequence, 100, stdin);
   
   
}

void converte(const char sequence[], char escapedSequence[]) {
    

    for (int i = 0; sequence[i] != '\0'; i++) {
        switch (sequence[i]) {
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
                escapedSequence[i++] = sequence[i];
                break;
        }
    }

   
}



int main() {
    char sequence[100];
    char escapedSequence[200];
   

    insiraTexto(sequence);

    converte(sequence, escapedSequence);

    imprimirSequenciaEscapada(escapedSequence);
   
    printf("Sequcia escapada: %s\n", escapedSequence);

    return 0;
}
