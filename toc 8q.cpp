#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int delta(int state, char input)
{
    switch (state) {
        case 0:
            if (input == 'b')
                return 1;
            else
                return -1;
        case 1:
            if (input == 'a')
                return 2;
            else if (input == 'b')
                return 1;
            else
                return -1;
        case 2:
            return -1;
        default:
            return -1;
    }
}
int main()
{
    char input[100];
    int currentState = 0;
    int i;
    printf("Enter a string: ");
    scanf("%s", input);
    for (i = 0; i < strlen(input); i++) {
        currentState = delta(currentState, input[i]);
        if (currentState == -1)
            break;
    }
    if (currentState == 2)
        printf("String is accepted by the NFA\n");
    else
        printf("String is not accepted by the NFA\n");
    return 0;
}
