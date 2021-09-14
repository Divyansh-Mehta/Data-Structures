#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *pre;
    int data;
    struct node *next;
} *first = NULL;

void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->pre = first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        t->pre = last;
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

int length(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insert(struct node *p, int pos, int x)
{
    int i;
    struct node *t;
    if (pos < 0 || pos > length(p))
        return;

    if (pos == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->pre = NULL;
        t->next = first;
        first->pre = t;
        first = t;
    }

    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->pre = p;
        t->next = p->next;
        if (p->next != NULL)
        {
            p->next->pre = t;
        }
        p->next = t;
    }
}

int delete (struct node *p, int pos)
{
    int x = -1, i;
    if (pos < 1 || pos > length(p))
        return -1;

    if (pos == 1)
    {
        first = first->next;
        if (first != NULL)
            first->pre = NULL;
        x = p->data;
        free(p);
    }

    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        p->pre->next = p->next;
        if (p->next != NULL)
            p->next->pre = p->pre;
        x = p->data;
        free(p);
    }

    return x;
}

void reverse(struct node *p)
{
    struct node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->pre;
        p->pre = temp;
        p = p->pre;

        if (p != NULL && p->next == NULL)
            first = p;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    reverse(first);
    display(first);

    return 0;
}