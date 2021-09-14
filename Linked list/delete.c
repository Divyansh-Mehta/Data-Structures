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

int delete (struct node *p, int pos)
{
    int x = -1, i;
    struct node *q = NULL;

    if (pos < 0 || pos > count(p))
        return -1;

    if (pos == 1)
    {
        first = first->next;
        x = p->data;
        free(p);
    }
    else
    {
        for (i = 0; i < pos - 1 && p != NULL; i++)
        {
            q = p;
            p = p->next;
        }
        if (p != NULL)
        {
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }
    return x;
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
    insert_last(10);
    insert_last(20);
    insert_last(30);
    insert_last(40);
    if (delete (first, 5) != -1)
        printf("Element deleted %d\n", delete (first, 5));
    else
        printf("Enter correct position\n");
    display(first);

    return 0;
}