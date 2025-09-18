#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];

    printf("enter first string: ");
    gets(str1);

    printf("enter second string: ");
    gets(str2);

    printf("length of first string = %lu\n", strlen(str1));
    printf("length of first string = %lu\n", strlen(str2));

    if (strcmp(str1, str2) == 0)
        printf("both string are equal.");
    else
        printf("string are not equal.");

    return 0;
}
