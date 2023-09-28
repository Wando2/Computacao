#include <stdio.h>
#include <stdlib.h>

// Function to convert an octal digit to binary
char *octalToBinary(char octal)
{
    int num = octal - '0';
    char *binary = (char *)malloc(4 * sizeof(char));
    int i;

    for (i = 2; i >= 0; i--)
    {
        binary[i] = (num % 2) + '0';
        num /= 2;
    }

    binary[3] = '\0';
    return binary;
}

// Function to convert an octal digit to hexadecimal
char octalToHex(char octal)
{
    int num = octal - '0';

    if (num >= 0 && num <= 7)
    {
        if (num <= 9)
            return num + '0';
        else
            return num - 10 + 'A';
    }

    return '\0'; // Invalid octal digit
}

int main()
{
    char octal;
    printf("");
    scanf(" %c", &octal);

    // Convert octal to binary
    char *binary = octalToBinary(octal);

    // Convert octal to hexadecimal
    char hex = octalToHex(octal);

    printf("Binário: %s\n", binary);
    printf("Hexadecimal: %c\n", hex);

    free(binary);

    return 0;
}
