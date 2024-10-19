#include <stdio.h>
#include <string.h>
#define BUFFER_LENGTH 100

int rIndex(char s[], char t)
{
    int slength = strlen(s) - 1;
    for (int i = slength; i >= 0; i--)
    {
        if (s[i] == t)
            return (slength - i);
    }
    return -1;
}

int main()
{
    char input[BUFFER_LENGTH];
    char target;

    printf("Enter string: ");
    fgets(input, BUFFER_LENGTH, stdin);
    printf("Enter target: ");
    scanf("%c", &target);
    printf("%d\n", rIndex(input, target));

    return 0;
}