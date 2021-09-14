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

int count(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void insert(struct node *p, int index, int x)
{
    int i;
    if(index < 0 || index > count(first))
    return;

    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(i = 0; i < index - 1; i++)
        p = p->next;

        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    insert(first, 0, 0);
    insert(first, 6, 6);
    display(first);

    return 0;
}
