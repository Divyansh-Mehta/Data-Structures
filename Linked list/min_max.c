#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define M INT_MAX
#define m INT_MIN

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

int max(struct node *p)
{
    int max = m;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int max_r(struct node *p)
{
    int x = 0;
    if (p == NULL)
        return m;

    x = max_r(p->next);
    return x > (p->data) ? x : (p->data);
}

int min(struct node *p)
{
    int min = M;
    while (p != NULL)
    {
        if (p->data < min)
            min = p->data;

        p = p->next;
    }
    return min;
}

int min_r(struct node *p)
{
    int x = 0;
    if (p == NULL)
        return M;

    x = min_r(p->next);
    return x < (p->data) ? x : (p->data);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    printf("%d ", min_r(first));
    printf("%d ", max_r(first));
    return 0;
}
