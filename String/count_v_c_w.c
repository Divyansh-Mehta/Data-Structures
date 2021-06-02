#include <stdio.h>

void cvcount(char *ch)
{
    int i = 0, vcount = 0, ccount = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' || ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U')
            vcount++;

        else if ((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z'))
            ccount++;

        i++;
    }

    printf("\nNo of vowels are %d\nNo of consonants are %d", vcount, ccount);
}

void wcount(char *ch)
{
    int i = 0, word = 1;
    while (ch[i] != '\0')
    {
        if (ch[i] == ' ' && ch[i - 1] != ' ')
            word++;

        i++;
    }
    printf("\nNo of words are %d", word);
}

int main()
{
    char ch[] = "how are  you";
    cvcount(ch);
    wcount(ch);
    return 0;
}