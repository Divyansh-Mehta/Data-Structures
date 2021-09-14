#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * first;

void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int sum(struct node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sum_r(struct node *p)
{
    if (p != NULL)
        return sum_r(p->next) + p->data;

    return 0;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    printf("%d", sum(first));

    return 0;
}
