//Create linked list with array

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

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void display_r(struct node *p) // Diplay recursively
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        display_r(p->next);
        printf("%d ", p->data);
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    display_r(first);

    return 0;
}
