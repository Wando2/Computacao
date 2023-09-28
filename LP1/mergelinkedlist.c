#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct coord
{
    int x;
    int y;
    struct coord *prox;
};

void insere(int x, int y, struct coord **p)
{

    struct coord *N = malloc(sizeof(*N));
    N->prox = *p;
    N->x = x;
    N->y = y;
    *p = N;
}

void remover(int x, int y, struct coord **p)
{

    if ((*p) != NULL)
    {
        if ((*p)->x == x && (*p)->y == y)
        {
            struct coord *node = *p;
            *p = node->prox;
            free(node);
        }

        else
        {

            remover(x, y, &((*p)->prox));
        }
    }

    else
    {
        printf("botafogo de guarapicui");
    }
}

struct coord *getMid(struct coord *p)
{
    struct coord *slow = p;
    struct coord *fast = slow->prox;
    while (fast != NULL && fast->prox != NULL)
    {
        slow = slow->prox;
        fast = fast->prox->prox;
    }

    return slow;
}

double distanceToOrigin(int x, int y)
{
    return sqrt(x * x + y * y);
}

struct coord *merge(struct coord *left, struct coord *right)
{
    if (left == NULL)
    {
        return right;
    }

    if (right == NULL)
    {
        return left;
    }

    struct coord *resultado;

    if (distanceToOrigin(left->x, left->y) < distanceToOrigin(right->x, right->y))
    {
        resultado = left;
        resultado->prox = merge(left->prox, right);
    }

    else
    {
        resultado = right;
        resultado->prox = merge(left, right->prox);
    }

    return resultado;
}

void mergeSort(struct coord **p)
{
    if ((*p) == NULL || (*p)->prox == NULL)
    {
        return;
    }

    struct coord *left = NULL;
    struct coord *right = NULL;
    struct coord *tmp = NULL;

    left = *p;
    right = getMid(*p);
    tmp = right->prox;
    right->prox = NULL;
    right = tmp;

    mergeSort(&left);
    mergeSort(&right);

    *p = merge(left, right);
}

void printarr(struct coord *p)
{
    if (p != NULL)
    {
        printf("(%d,%d) ", p->x, p->y);
        printarr(p->prox);
    }
}

int main(void)
{
    struct coord *head = NULL;
    insere(2, 3, &head);
    insere(4, 7, &head);
    insere(5, 5, &head);
    insere(1, 9, &head);
    insere(1, 3, &head);
    insere(1, 6, &head);
    mergeSort(&head);

    printarr(head);
}