#include <stdio.h>
#include <stdlib.h>

short le_numero(FILE *arquivo)
{
    short digito, numero = 0;
    do
    {
        digito = getc(arquivo);
        if ((digito != ' ') && (digito != '\n'))
            numero = numero * 10 + (digito - '0');
    } while ((digito != ' ') && (digito != '\n'));
    return numero;
}

void switchD(int **matriz1, int **matriz2, short linha, short coluna)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz2[i][j] = matriz1[j][i];
        }
    }
}

int leArquivoEntrada(FILE *fotoE, FILE *fotoS)
{
    char formato[2] = {0};
    short linha;
    short coluna;
    short sla;

    fscanf(fotoE, "%s", formato);
    fscanf(fotoE, "%hd", &linha);
    fscanf(fotoE, "%hd", &coluna);
    fscanf(fotoE, "%hd", &sla);

    int **matriz = (int **)malloc(linha * sizeof(int *));
    for (int i = 0; i < linha; i++)
    {
        matriz[i] = (int *)malloc(coluna * sizeof(int));
    }

    for (int j = 0; j < linha; j++) // atribuir valores
    {
        for (int k = 0; k < coluna; k++)
        {
            fscanf(fotoE, "%d", &matriz[j][k]);
        }
    }
    for (int p = 0; p < linha; p++) // printar matriz
    {
        for (int l = 0; l < coluna; l++)
        {
            printf("%d   ", matriz[p][l]);
        }
    }

    fprintf(fotoS, "P2\n");
    fprintf(fotoS, "%hd %hd\n", coluna, linha);
    fprintf(fotoS, "255\n");

    int **matrizInvertida = (int **)malloc(4 * sizeof(int *));
    for (int y = 0; y < 4; y++)
    {
        matrizInvertida[y] = (int *)malloc(3 * sizeof(int));
    }

    switchD(matriz, matrizInvertida, linha, coluna);

    printf("Matriz Invertida:\n");
    for (int i = 0; i < coluna; i++)
    {
        for (int j = 0; j < linha; j++)
        {
            printf("%d ", matrizInvertida[i][j]);
        }
        printf("\n");
    }

    for (int w = 0; w < 4; w++)
    {
        for (int z = 0; z < 3; z++)
        {
            fprintf(fotoS, "%d ", matrizInvertida[w][z]);
        }

        fprintf(fotoS, "\n");
    }
}

int main()
{
    FILE *foto = fopen("fotoEntrada.pgm", "r");
    FILE *fotoSaida = fopen("fotoSaida.pgm", "w");
    leArquivoEntrada(foto, fotoSaida);
}
