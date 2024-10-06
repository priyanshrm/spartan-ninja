#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#define BUFFER_LENGTH 100

int main()
{
    char line[BUFFER_LENGTH];
    while (fgets(line, BUFFER_LENGTH, stdin) && line[0] != '\n')
    {
        int len = 0;
        bool toPrint = false;
        for (; line[len] != '\0'; len++)
        {
            if (len > 10)
                toPrint = true;
        }
        toPrint &&printf("%s", line);
    }

    return 0;
}