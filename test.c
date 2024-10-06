#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#define BUFFER_LENGTH 100

int main()
{
    char line[BUFFER_LENGTH];
    FILE *hand;
    hand = fopen("romeo.txt", "r");
    while (fgets(line, BUFFER_LENGTH, hand) != NULL)
    {
        int lastNonBlank = -1;
        for (int i = 0; line[i] != '\n'; i++)
        {
            if ((line[i] != ' ') && (line[i] != '\t'))
                lastNonBlank = i;
        }

        if (lastNonBlank > -1)
        {
            line[lastNonBlank + 1] = '\0';
            printf("%s.\n", line);
            // printf("%d", lastNonBlank);
        }
    }
    fclose(hand);

    return 0;
}