#include <stdio.h>
#include <stdlib.h>
#define MAX_STATES 50
int num_states, num_symbols, num_final_states;
int start_state, final_states[MAX_STATES], nfa[MAX_STATES][MAX_STATES][MAX_STATES];
void epsilon_closure(int state, int* closure) {
    int i, j;
    for (i = 0; i < num_states; i++) {
        if (nfa[state][0][i] && !closure[i]) {
            closure[i] = 1;
            epsilon_closure(i, closure);
        }
    }
}
int main() {
    int i, j, k;
    printf("Enter the number of states in NFA: ");
    scanf("%d", &num_states);
    printf("Enter the number of input symbols: ");
    scanf("%d", &num_symbols);
    printf("Enter the start state: ");
    scanf("%d", &start_state);
    printf("Enter the number of final states: ");
    scanf("%d", &num_final_states);
    printf("Enter the final states: ");
    for (i = 0; i < num_final_states; i++) {
        scanf("%d", &final_states[i]);
    }
    printf("Enter the transition table of NFA: \n");
    for (i = 0; i < num_states; i++) {
        for (j = 0; j < num_symbols + 1; j++) {
            printf("nfa[%d][%d][]: ", i, j);
            for (k = 0; k < num_states; k++) {
                scanf("%d", &nfa[i][j][k]);
            }
        }
    }
    printf("Epsilon Closures:\n");
    for (i = 0; i < num_states; i++) {
        int closure[MAX_STATES] = {0};
        closure[i] = 1;
        epsilon_closure(i, closure);

        printf("E-closure(%d) = {", i);
        for (j = 0; j < num_states; j++) {
            if (closure[j]) {
                printf("%d ", j);
            }
        }
        printf("}\n");
    }
    return 0;
}
