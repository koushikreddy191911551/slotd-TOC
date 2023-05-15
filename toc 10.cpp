#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int n, e;
int closure[MAX][MAX], nfa[MAX][MAX];

void epsilon_closure(int state, int cur_state, int *size) {
    int i;
    for(i = 0; i < n; i++) {
        if(nfa[cur_state][i] == state && closure[state][i] != 1) {
            closure[state][i] = 1;
            *size += 1;
            epsilon_closure(state, i, size);
        }
    }
}

int main() {
    int i, j, k, size;
    printf("Enter the number of states in NFA: ");
    scanf("%d", &n);
    printf("Enter the number of input symbols: ");
    scanf("%d", &e);

    printf("Enter the transition table of NFA: \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < e; j++) {
            printf("nfa[%d][%d]: ", i, j);
            scanf("%d", &nfa[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            closure[i][j] = 0;
        }
    }

    for(i = 0; i < n; i++) {
        size = 0;
        epsilon_closure(i, i, &size);
        printf("E-closure(%d) = {", i);
        printf("%d", i);
        for(j = 0; j < n; j++) {
            if(closure[i][j] == 1) {
                printf(", %d", j);
            }
        }
        printf("}\n");
    }

    return 0;
}

