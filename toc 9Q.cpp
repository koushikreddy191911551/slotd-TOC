#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STATES 100
#define MAX_SYMBOLS 100
int n_states, n_symbols, n_final_states;
int start_state, final_states[MAX_STATES];
int transitions[MAX_STATES][MAX_SYMBOLS][MAX_STATES];
void simulate_nfa(char* input_string) {
    int i, j, k, cur_state, next_states[MAX_STATES], num_next_states;
    int cur_states[MAX_STATES];
    memset(cur_states, 0, sizeof(cur_states));
    cur_states[start_state] = 1;
    for (i = 0; i < strlen(input_string); i++) {
        num_next_states = 0;
        for (j = 0; j < n_states; j++) {
            if (cur_states[j] == 1) {
                for (k = 0; k < n_states; k++) {
                    if (transitions[j][input_string[i]-'0'][k] == 1) {
                        next_states[k] = 1;
                    }
                }
            }
        }
        memcpy(cur_states, next_states, sizeof(cur_states));
    }
    for (i = 0; i < n_states; i++) {
        if (cur_states[i] == 1) {
            for (j = 0; j < n_final_states; j++) {
                if (i == final_states[j]) {
                    printf("Accepted\n");
                    return;
                }
            }
        }
    }
    printf("Rejected\n");
}
int main() {
    int i, j, k;
    n_states = 4;
    n_symbols = 2;
    start_state = 0;
    n_final_states = 1;
    final_states[0] = 3;
    transitions[0][0][1] = 1;
    transitions[1][1][2] = 1;
    transitions[2][1][3] = 1;
    char input_string[MAX_SYMBOLS];
    printf("Enter the input string: ");
    scanf("%s", input_string);
    simulate_nfa(input_string);
    return 0;
}
