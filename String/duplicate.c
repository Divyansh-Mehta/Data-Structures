#include <stdio.h>

void duplicate(char *a)
{
    int h[127] = {0}, i = 0;
    while (a[i] != '\0')
    {
        h[a[i]]++;
        i++;
    }

    for (i = 0; i < 127; i++)
    {
        if (h[i] > 1)
        {
            printf("\n%c has appeared %d times", i, h[i]);
        }
    }
}

void duplicat_bit(char *a)
{
    int i = 0;
    unsigned long long h = 0, x;

    while (a[i] != '\0')
    {
        x = 1;
        x = x << (a[i] - 65);
        if ((x & h) > 0)
        {
            printf("%c ", a[i]);
        }
        else
            h = h | x;

        i++;
    }
}
int main()
{
    char ch[] = "ABCABC";
    duplicat_bit(ch);

    return 0;
}