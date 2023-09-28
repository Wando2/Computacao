#include <stdio.h>

void incrementa(int *num);

int main()
{
    int num = 9;
    incrementa (&num);
    printf("%d",num);
    return 0;
}

 void incrementa (int *num) {
    *num = *num +1;
}

