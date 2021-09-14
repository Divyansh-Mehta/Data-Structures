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

struct node *search(struct node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct node *search_r(struct node *p, int key)
{
    if (p == NULL)
        return NULL;
    else if (p->data == key)
        return p;

    return search_r(p->next, key);
}

struct node *search_m(struct node *p, int key)
{
    struct node *q = NULL;
    if (first->data == key)
        return first;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    struct node *p;
    p = search(first, 1);
    printf("%d ", p);
    p = search_r(first, 1);
    printf("%d ", p);
    p = search_m(first, 1);
    printf("%d ", p);
    return 0;
}
