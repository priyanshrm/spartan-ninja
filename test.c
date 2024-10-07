#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define BUFFER_LENGTH 100

int getStrLength(char arr[])
{
    int i = 0;
    while (arr[i] != '\0' && arr[i] != '\n')
        i++;
    return i;
}

int findIndex(char arr[], char target)
{
    int length = getStrLength(arr);
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

void deleteChars(char str1[], char str2[])
{
    char result[BUFFER_LENGTH];
    int c = 0;
    int str1len = getStrLength(str1);
    for (int i = 0; i < str1len; i++)
    {
        if (findIndex(str2, str1[i]) != -1)
            continue;
        result[c] = str1[i];
        c++;
    }
    printf("%s", result);
}

int main()
{
    char str1[BUFFER_LENGTH];
    char str2[BUFFER_LENGTH];
    printf("Enter a string 1: ");
    fgets(str1, BUFFER_LENGTH, stdin);
    printf("Enter a string 2: ");
    fgets(str2, BUFFER_LENGTH, stdin);
    deleteChars(str1, str2);
    return 0;
}