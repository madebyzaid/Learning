#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[50];

    printf("Enter a string: ");
    scanf("%49[^\n]", str);

    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    printf("Reversed string: %s\n", str);
    return 0;
}