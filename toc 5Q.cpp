#include <stdio.h>
#include <string.h>
int belongsToLanguage(char* str, int start, int end)
{
    if (start > end) {
        return 1;
    }

    if (str[start] == '0' && str[end] == '0' && belongsToLanguage(str, start + 1, end - 1)) {
        return 1;
    }
    if (str[start] == '1' && belongsToLanguage(str, start + 1, end)) {
        return 1;
    }
    if (str[start] == 'e') {
        return 1;
    }

    return 0;
}
int main()
{
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);
    if (belongsToLanguage(input, 0, strlen(input) - 1)) {
        printf("The string belongs to the language.\n");
    } else {
        printf("The string does not belong to the language.\n");
    }

    return 0;
}

