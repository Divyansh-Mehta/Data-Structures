#include <stdio.h>

int check_palindrome(char *ch)
{
    int i = 0, j = 0;
    for (; ch[j] != '\0'; j++)
    {
    }
    j--;
    while (i < j)
    {
        if (ch[i] != ch[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main()
{
    char ch[] = "nam  man";
    if (check_palindrome(ch))
        printf("Palindrome");
    else
        printf("Not palindrome");

    return 0;
}