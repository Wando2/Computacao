#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int atoi2(char *s)
{
    int i, n;
    n = 0;
    for (i = 0; *(s + i) >= '0' && *(s + i) <= '9'; ++i)
        n = 10 * n + (*(s + i) - '0');
    return n;
}

int main()
{
    char urubu[] = "21";

    printf("%d tira o sono", atoi2(urubu));
}
