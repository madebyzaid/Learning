#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[50];
    char rStr[50];

    printf("Enter a string: ");
    scanf("%49[^\n]", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        rStr[i] = str[len - 1 - i];
    }
    rStr[len] = '\0';

    if (strcmp(str, rStr) == 0)
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}