#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void madmax(float *min, float *max)
{

    if (*min > *max)
    {
        float temp = *max;
        *max = *min;
        *min = temp;
    }
}

int main()
{

    float min = 20;
    float max = 10;
    printf("antes MIN E MAX %f ,%f", min, max);
    madmax(&min, &max);
    printf("depos MIN E MAX %f ,%f", min, max);
}

