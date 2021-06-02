#include <stdio.h>

int length(char *ch)
{
    int i = 0;
    while (ch[i] != '\0')
    {
        i++;
    }
    return i;
}

int main()
{
    char *ch = "Welcome";
    printf("Length of %s is %d", ch, length(ch));

    return 0;
}