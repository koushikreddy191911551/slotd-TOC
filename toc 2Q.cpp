#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int currentState = 0;
    int finalState = 1;
    int transitionTable[][2] = {{1, 0}, {2, 1}, {2, 2}};

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        char input = str[i];

        if (input == '0') {
            currentState = transitionTable[currentState][0];
        } else {
            currentState = transitionTable[currentState][1];
        }
    }

    if (currentState == finalState) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
