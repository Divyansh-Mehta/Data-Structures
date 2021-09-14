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

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void reverse(struct node *p)
{
    struct node *q = p;
    int *a = (int *)malloc(count(first)*sizeof(int)), i = 0;
    while(p != NULL)
    {
        a[i++] = p->data;
        p = p->next;
    }
    p = q;
    i--;
    while(p != NULL)
    {
        p->data = a[i--];
        p = p->next;
    }
}

void reverse_l(struct node *p)
{
    struct node *r = NULL, *q = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse_r(struct node *q, struct node *p)
{
    if(p != NULL)
    {
        reverse_r(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    insert_last(10);
    insert_last(20);
    insert_last(30);
    insert_last(40);
    reverse(first);
    reverse_l(first);
    reverse_r(NULL ,first);

 

    display(first);

    return 0;
}