#include <stdio.h>

float f2c (int);

int main() {
    for (float f = 20; f <= 200; f += 20) {
    printf("%d", f2c(f));

    }
    
}

float f2c (int f) {
    float c;
    c = (f*9/5) + 32;
    return c;


}