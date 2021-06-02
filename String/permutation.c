#include <stdio.h>

void perem(char s[], int k)
{
    static int a[10] = {0};
    static char res[10];
    int i;

    if (s[k] == '\0')
    {
        res[k] = '\0';
        printf("\n%s", res);
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (a[i] == 0)
            {
                res[k] = s[i];
                a[i] = 1;
                perem(s, k + 1);
                a[i] = 0;
            }
        }
    }
}

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void perem_spaw(char s[], int l, int h)
{
    int i;
    if (l == h)
    {
        printf("\n%s", s);
    }
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(&s[i], &s[l]);
            perem_spaw(s, l + 1, h);
            swap(&s[i], &s[l]);
        }
    }
}

int main()
{
    char ch[] = "ABC";
    perem_spaw(ch, 0, 2);

    return 0;
}