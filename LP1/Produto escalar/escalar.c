#include "escalar.h"

float produtoEscalarRecursivo(float vetor1[], float vetor2[], int n) {
    if (n == 0) {
        return 0.0;
    } else {
        return (vetor1[n - 1] * vetor2[n - 1]) + produtoEscalarRecursivo(vetor1, vetor2, n - 1);
    }
}
