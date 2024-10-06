#include <stdio.h>

#define BUFFER_LENGTH 100

int getStrLength(char arr[])
{
    int i = 0;
    while (arr[i] != '\0' && arr[i] != '\n')
        i++;
    return i;
}

int main()
{
    char line[BUFFER_LENGTH];
    FILE *hand;
    hand = fopen("romeo.txt", "r");
    while (fgets(line, BUFFER_LENGTH, hand) != NULL)
    {
        int len = getStrLength(line);
        for (int i = 0; i <= len / 2; i++)
        {
            char temp = line[i];
            line[i] = line[len - i];
            line[len - i] = temp;
        }
        printf("%s", line);
    }

    fclose(hand);

    return 0;
}