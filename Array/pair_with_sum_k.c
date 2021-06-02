#include <stdio.h>
#include <stdlib.h>

void find_pair(int a[], int n, int k)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == k)
                printf("\n%d + %d = %d", a[i], a[j], k);
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

void find_pair_hash(int a[], int n, int k)
{
    int i, H = max(a, n);
    int *h = (int *)calloc(H + 1, sizeof(int));
    for (i = 0; i < n; i++)
    {
        if (h[k - a[i]] == 1)
        {
            printf("\n%d + %d = %d", a[i], k - a[i], k);
        }
        h[a[i]]++;
    }
}

void find_pair2(int a[], int n, int k)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] == k)
        {
            printf("\n%d + %d = %d", a[i], k - a[i], k);
            i++;
            j--;
        }
        else if (a[i] + a[j] < k)
            i++;
        else
            j--;
    }
}

int main()
{
    int a[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    find_pair2(a, 10, 10);
    find_pair_hash(a, 10, 10);
    int b[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    find_pair(b, 10, 10);
    return 0;
}