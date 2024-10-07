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

int htoi(char hexInput[])
{
    int base10result = 0;
    int strLength = getStrLength(hexInput);
    strLength--;

    for (int i = 0; i <= strLength; i++)
    {
        switch (tolower(hexInput[i]))
        {
        case 'a':
            base10result += 10 * pow(16, (strLength - i));
            break;
        case 'b':
            base10result += 11 * pow(16, (strLength - i));
            break;
        case 'c':
            base10result += 12 * pow(16, (strLength - i));
            break;
        case 'd':
            base10result += 13 * pow(16, (strLength - i));
            break;
        case 'e':
            base10result += 14 * pow(16, (strLength - i));
            break;
        case 'f':
            base10result += 15 * pow(16, (strLength - i));
            break;
        default:
            base10result += (hexInput[i] - '0') * pow(16, (strLength - i));
            break;
        }
    }

    return base10result;
}

int main()
{

    char hexInput[BUFFER_LENGTH];
    printf("Enter a hexadecimal number: ");
    fgets(hexInput, BUFFER_LENGTH, stdin);
    printf("%d", htoi(hexInput));
    return 0;
}