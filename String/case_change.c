#include <stdio.h>

void case_change(char *c)
{
    int i = 0;
    while (c[i] != '\0')
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
            c[i] += 32;

        else if (c[i] >= 'a' && c[i] <= 'z')
            c[i] -= 32;

        i++;
    }
}

int main()
{
    char ch[] = "WeLcOMe";
    case_change(ch);
    printf(ch);
}