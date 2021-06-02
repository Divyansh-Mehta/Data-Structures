#include <stdio.h>

void reverse(char *ch)
{
    int i = 0, j;
    char temp;
    for (j = 0; ch[j] != '\0'; j++)
    {
    }
    j--;
    while (i < j)
    {
        temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char ch[] = "PYTHON";
    reverse(ch);
    printf(ch);

    return 0;
}