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

int check_loop(struct node *f)
{
    struct node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while (p != NULL && q != NULL && p != q);

    return p == q ? 1 : 0;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    struct node *t1, *t2;
    create(a, 5);

    if (check_loop(first))
        printf("Loop\n");
    else
        printf("Not Loop\n");

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;

    if (check_loop(first))
        printf("Loop\n");
    else
        printf("Not Loop\n");

    return 0;
}
