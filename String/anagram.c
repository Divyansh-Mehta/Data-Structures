// Two strings are called anagram if they are formed with same set if chareacters
#include <stdio.h>

int check_anagram(char *a, char *b)
{
    int i, h[128] = {0};

    for (i = 0; a[i] != '\0'; i++)
    {
        h[a[i]]++;
    }

    for (i = 0; b[i] != '\0'; i++)
    {
        h[b[i]]--;
    }
    for (i = 0; i < 128; i++)
    {
        if (h[i] != 0)
            return 0;
    }
    return 1;
}

int main()
{
    char a[] = "medical";
    char b[] = "decimal";
    if (check_anagram(a, b))
        printf("They are anagram");
    else
        printf("They are not anagram");

    return 0;
}