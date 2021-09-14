#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * first, *second, *third;

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

void create2(int a[], int n)
{
    int i;
    struct node *t, *last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = a[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void concat(struct node *p, struct node *q)
{
    third = p;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}


int main()
{
    int a[] = {1, 3, 6, 8, 9}, b[] = {2, 4, 5, 7, 10};
    create(a, 5);
    create2(b, 5);
    concat(first, second);
    display(third);

    return 0;
}
