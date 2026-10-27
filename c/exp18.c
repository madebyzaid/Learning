#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];

    printf("Enter a sentence: ");
    scanf("%99[^\n]", str);

    int len = strlen(str);
    int end = len;
    int first = 1;

    printf("Reversed sentence: ");
    for (int i = len; i >= 0; i--)
    {
        if (i == 0 || str[i - 1] == ' ')
        {
            if (end > i)
            {
                if (!first)
                {
                    printf(" ");
                }
                printf("%.*s", end - i, str + i);
                first = 0;
            }
            end = i - 1;
        }
    }
    printf("\n");
    return 0;
}