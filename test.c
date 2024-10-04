#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#define BUFFER_LENGTH 100
#define NUMBER_WORDS 10

int maxWordCount(char arr[])
{
    int max = INT_MIN;
    for (int i = 0; i < NUMBER_WORDS; i++)
    {
        if (arr[i] >= max)
            max = arr[i];
    }
    return max;
}
int main()
{
    int wordsCountArr[NUMBER_WORDS] = {};
    int count = 0;
    char line[BUFFER_LENGTH];
    printf("Enter a sentence: \n");
    fgets(line, BUFFER_LENGTH, stdin);
    for (int i = 0; i < BUFFER_LENGTH; i++)
    {
        if (line[i] == '\0')
            break;

        if (isalpha(line[i]))
            count++;
        else
        {
            wordsCountArr[count - 1]++;
            count = 0;
        }
    }
    while (maxWordCount(wordsCountArr) > 0)
    {
        int max = maxWordCount(wordsCountArr);
        for (int i = 0; i < NUMBER_WORDS; i++)
        {
            if (wordsCountArr[i] == max)
            {
                wordsCountArr[i]--;
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < NUMBER_WORDS; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\n");

    return 0;
}
