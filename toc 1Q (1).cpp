#include <stdio.h>
#include <stdbool.h>

#define NUM_STATES 3
#define NUM_SYMBOLS 2

int dfa_table[NUM_STATES][NUM_SYMBOLS] = {{1, 2},
                                          {1, 2},
                                          {1, 2}};
bool is_valid_string(char str[]) {
    int current_state = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == 'a') {
            current_state = dfa_table[current_state][0];
        }
        else if (str[i] == 'b') {
            current_state = dfa_table[current_state][1];
        }
        i++;
    }
    return current_state == 1;
}

int main() {
    char str[100];
    printf("Enter a string over the alphabet {a,b}: ");
    scanf("%s", str);
    if (is_valid_string(str)) {
        printf("Valid string\n");
    }
    else {
        printf("Invalid string\n");
    }
    return 0;
}
