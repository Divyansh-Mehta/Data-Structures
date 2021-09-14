#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void insert_sorted(struct node *p, int x)
{
    struct node *t, *q = NULL;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = t;
    else
    {
        while (p != NULL && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
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

int main()
{
    insert_sorted(first, 10);
    insert_sorted(first, 9);
    insert_sorted(first, 11);

    display(first);

    return 0;
}