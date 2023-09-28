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
    if (*p != NULL)
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

double distanceToOrigin(int x, int y)
{
    return sqrt(x * x + y * y);
}

struct coord *merge(struct coord *left, struct coord *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    struct coord *result;

    if (distanceToOrigin(left->x, left->y) < distanceToOrigin(right->x, right->y))
    {
        result = left;
        result->prox = merge(left->prox, right);
    }
    else
    {
        result = right;
        result->prox = merge(left, right->prox);
    }

    return result;
}

void split(struct coord *source, struct coord **front, struct coord **back)
{
    struct coord *fast;
    struct coord *slow;

    if (source == NULL || source->prox == NULL)
    {
        *front = source;
        *back = NULL;
    }
    else
    {
        slow = source;
        fast = source->prox;

        while (fast != NULL)
        {
            fast = fast->prox;
            if (fast != NULL)
            {
                slow = slow->prox;
                fast = fast->prox;
            }
        }

        *front = source;
        *back = slow->prox;
        slow->prox = NULL;
    }
}

void mergeSort(struct coord **headRef)
{
    struct coord *head = *headRef;
    struct coord *left;
    struct coord *right;

    if (head == NULL || head->prox == NULL)
        return;

    split(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headRef = merge(left, right);
}

void imprimirLista(struct coord *p)
{
    while (p != NULL)
    {
        printf("(%d, %d) ", p->x, p->y);
        p = p->prox;
    }
    printf("\n");
}

int main(void)
{
    struct coord *head = NULL;
    insere(2, 3, &head);
    insere(4, 7, &head);
    insere(5, 5, &head);
    insere(1, 9, &head);
    insere(4, 7, &head);
    insere(5, 5, &head);
    insere(1, 9, &head);

    printf("Lista original: ");
    imprimirLista(head);

    mergeSort(&head);

    printf("Lista ordenada por distância euclidiana: ");
    imprimirLista(head);

    return 0;
}
