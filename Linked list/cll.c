#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

void display_r(struct node *p)
{
    static int x = 0;
    if (p != head || x == 0)
    {
        x = 1;
        printf("%d ", p->data);
        display_r(p->next);
    }
    x = 0;
}

int length(struct node *p)
{
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}

void insert(struct node *p, int pos, int x)
{
    struct node *t;
    int i;
    if (pos < 1 || pos > length(p))
        return;

    if (pos == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;

        if (head == NULL)
        {
            head = t;
            head->next = head;
        }

        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int delete (struct node *p, int pos)
{
    struct node *q;
    int i;
    int x;

    if (pos < 0 || pos > length(head))
        return -1;

    if (pos == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }

    else
    {
        for (i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }

    return x;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    delete (head, 1);
    display(head);
    delete (head, 2);
    display_r(head);

    return 0;
}