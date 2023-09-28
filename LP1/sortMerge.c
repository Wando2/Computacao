#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printText(char *[], int);
void sortText(char *[], int);
void swap(char *[], int, int);

int main(void)
{
    char *text[] = {"defghi", "jklmnopqrst", "abc"};
    printText(text, 3);
    sortText(text, 3);
    printText(text, 3);
    return 0;
}

void sortText(char *lText[], int Size)
{
    int i, j;
    for (i = Size - 2; i >= 0; i--)
        for (j = 0; j <= i; j++)
            if (strcmp(lText[j], lText[j + 1]) > 0)
                swap(lText, j, j + 1);
}
void swap(char *lText[], int i, int j)
{
    char *Temp;
    Temp = lText[i];
    lText[i] = lText[j];
    lText[j] = Temp;
}

void printText(char *lText[], int Size)
{
    printf("\n-------------------\n");
    while (Size > 0)
    {
        printf("%s\n", *lText++);
        Size--;
    }
    printf("-------------------\n");
}