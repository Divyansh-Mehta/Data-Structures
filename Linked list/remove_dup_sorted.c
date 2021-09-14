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

void remove_dup_sorted(struct node *p)
{
    struct node *q = p->next;
    while (q != NULL)
    {
        if (q->data != p->data)
        {
            p = q;
            q = q->next;
        }

        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

int main()
{
    insert_last(10);
    insert_last(20);
    insert_last(20);
    insert_last(30);
    insert_last(40);
    display(first);
    remove_dup_sorted(first);
    printf("\n");
    display(first);

    return 0;
}
