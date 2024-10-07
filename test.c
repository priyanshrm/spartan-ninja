#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define BUFFER_LENGTH 100

int main()
{
    int num, b;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("Enter no. of right shift: ");
    scanf("%d", &b);
    num = num >> b;
    printf("after shift: %d", num);

    return 0;
}