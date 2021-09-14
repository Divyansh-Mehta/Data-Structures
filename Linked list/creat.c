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

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);

    return 0;
}
