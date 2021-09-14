#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void insert_last(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
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

int check_sorted(struct node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;

        x = p->data;
        p = p->next;
    }

    return 1;
}

int main()
{
    insert_last(10);
    insert_last(20);
    insert_last(30);
    insert_last(40);
    if (check_sorted(first))
        printf("Sorted\n");
    else
        printf("Not sorted\n");
    display(first);

    return 0;
}