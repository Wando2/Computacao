#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* int main () {
    int* pCoord;
 int linha=1;
 pCoord=&linha;
 printf("linha: %d\n*", linha);
 printf("*pCoord: %d\n", (*pCoord)++);
 printf("linha: %d\n", linha);
 printf("*pCoord: %d\n",*pCoord);
 return 0;

} */

/* void swap (int*, int*);

int main()
{

int a = 10, b = 20;
swap(&a, &b);
printf("%d, %d\n",a,b);
 return 0;
}

void swap(int* x, int* y)
{
int temp;
temp = *x;
x = y;
*y = temp;
}

 */
/* 
int main()
{
short Vet[2];
 short* pVet = NULL;
pVet = Vet;
 *pVet=5;
pVet[0]=9;
 pVet[1]=10;
return 0;
}
 */

int strleny(char *s)
{
char *p = s;
while (*p != '\0')
p++;
return p - s;
}

void copy(char * to, char * from){
    int i = 0;
   while (( *(to+i) = from[i]) != '\0'){
        i++;
    }
}

int main()
{
int* pInt = malloc(5*sizeof(int));
pInt[0] = 4;
* (pInt+1) = 7;

int* JInt = calloc(5,sizeof(*pInt));

char kavalo[] = "kavalo?";
 int buceta = strleny(kavalo);
char  mamako[] = "makakakako";

copy(kavalo,mamako);

return 0;

}