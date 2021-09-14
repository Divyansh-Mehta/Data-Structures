#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};
void create(struct stack *st)
{
    int x;
    printf("\nEnter size of stack: ");
    scanf("%d", &x);
    st->size = x;
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("\nStack overflow"); // trying to push in a full stack

    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("\nStack underflow"); // trying to pop from an empty stack

    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0)
        printf("\nInvalid position");

    else
        x = st.s[st.top - pos + 1];

    return x;
}

int isEmpty(struct stack st)
{
    if (st.top == -1)
        return 1;

    return 0;
}

int isFull(struct stack st)
{
    if ((st.top) == (st.size - 1))
        return 1;

    return 0;
}

int stacktop(struct stack st)
{
    if (st.top == -1)
        return -1;
    else
        return st.s[st.top];
}

void display(struct stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

int main()
{
    struct stack st;
    int ch;
    do
    {
        printf("\n**********MENU**********\n");
        printf("1.Create\n2.Display\n3.push\n4.pop.\n5.Peek\n6.Check Empty\n7.Check full\n8.Stack top\n9.Exit\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            create(&st);
        }
        break;
        case 2:
        {
            display(st);
        }
        break;
        case 3:
        {
            int n;
            printf("\nEnter Element to push: ");
            scanf("%d", &n);
            push(&st, n);
        }
        break;
        case 4:
        {
            int x = pop(&st);
            if (x != -1)
                printf("\nElement poped: %d", x);
        }
        break;
        case 5:
        {
            int n, x;
            printf("\nEnter position: ");
            scanf("%d", &n);
            x = peek(st, n);
            if (x != -1)
                scanf("\nElement present at %d is %d", n, x);
        }
        break;
        case 6:
        {
            if (isEmpty(st))
                printf("\nStack is empty");
            else
                printf("\nStack is not empty");
        }
        break;
        case 7:
        {
            if (isFull(st))
                printf("Stack is full");
            else
                printf("Stack is not full");
        }
        break;
        case 8:
        {
            if (stacktop(st) != -1)
                printf("\nElement at top is %d", stacktop(st));
            else
                printf("\nStack empty");
        }
        break;
        case 9:
            break;
        default:
            printf("\nWrong choice");
        }
    } while (ch != 9);

    return 0;
}