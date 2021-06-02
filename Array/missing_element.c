#include <stdio.h>
#include <stdlib.h>

void missing_single(int a[], int n) // Only for sorted
{
    int i;
    int diff = a[0] - 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] - i != diff)
        {
            printf("%d", diff + i);
            break;
        }
    }
}

void missing_multiple(int a[], int n) // Only for sorted
{
    int i, diff = a[0] - 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] - i != diff)
        {
            while (diff < a[i] - i)
            {
                printf("%d\n", diff + i);
                diff++;
            }
        }
    }
}
int max(int a[], int n)
{
    int max = a[0], i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
int min(int a[], int n)
{
    int min = a[0], i;
    for (i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}
int missing_hash(int a[], int n) // any array
{
    int i, l = min(a, n), h = max(a, n);
    int *p = (int *)calloc(h + 1, sizeof(int));
    for (i = 0; i < n; i++)
    {
        p[a[i]]++;
    }
    for (i = l; i <= h; i++)
    {
        if (p[i] == 0)
            printf("%d\n", i);
    }
}

int main()
{
    /* int a[] = {4, 5, 6, 7, 9, 10};
    missing_single(a, sizeof(a)/sizeof(a[0])); 
    int b[] = {2, 4, 7, 15, 16, 19, 20, 22};
    missing_multiple(b, sizeof(b) / sizeof(b[0])); */
    int c[] = {3, 1, 7, 4, 6, 5, 10, 8};
    missing_hash(c, sizeof(c) / sizeof(c[0]));
    return 0;
}