#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define BUFFER_LENGTH 100

int ctoi(s)
char s;
{
    return (int)(s) - '0';
}

float stof(s)
char s[];
{
    int tens = 10;
    float result = 0.00 - 0.00;
    bool flag = false;
    int length = strlen(s) - 1;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '.')
        {
            flag = true;
            tens = 10;
            continue;
        }
        int num = ctoi(s[i]);
        if (num > 9 || num < 0)
        {
            printf("Invalid string. Cannot convert to float!\n");
            return -1.00;
        }
        if (flag)
        {
            result += (float)num / tens;
            tens *= 10;
            continue;
        }
        result = 10 * result + (float)num;
    }
    return result;
}

int main()
{
    char alpha[BUFFER_LENGTH];
    printf("Enter number: ");
    fgets(alpha, BUFFER_LENGTH, stdin);
    printf("%f", stof(alpha));

    return 0;
}