#include <stdio.h>
#include <stdlib.h>

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

void duplicate_sorted(int a[], int n) // Only for sorted array
{
    int i, ldip = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1] && ldip != a[i])
        {
            printf("%d ", a[i]);
            ldip = a[i];
        }
    }
}

void count_dup(int a[], int n) // for sorted array
{
    int i, j;
    i = j = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == a[i + 1])
        {
            j = i + 1;
            while (a[j] == a[i])
                j++;
            printf("\n%d is present %d times", a[i], j - i);
            i = j - 1;
        }
    }
}

void count_dup_hash(int a[], int n)
{
    int i, H = max(a, n);
    int *h = (int *)calloc(H + 1, sizeof(int));

    for (i = 0; i < n; i++)
    {
        h[a[i]]++;
    }
    for (i = 0; i <= H; i++)
    {
        if (h[i] > 1)
            printf("\n%d is appearing %d times", i, h[i]);
    }
}

void count_dup2(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int count = 1;
        if (a[i] != -1)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] == a[j])
                {
                    count++;
                    a[j] = -1;
                }
            }
        }
        if (count > 1)
            printf("\n%d appeared %d times", a[i], count);
    }
}
int main()
{
    int a[13] = {1, 2, 3, 4, 4, 8, 8, 5, 5, 6, 8, 9, 9};
    duplicate_sorted(a, 11);
    count_dup2(a, 13);
    return 0;
}