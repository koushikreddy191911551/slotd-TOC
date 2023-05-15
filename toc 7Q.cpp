#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
int is_valid(char str[MAX_LEN], int start, int end);
int main() {
    char str[MAX_LEN];
    printf("Enter a string to check whether it belongs to the language defined by the CFG S ? A101A, A ? 0A | 1A | e: ");
    scanf("%s", str);
    if (is_valid(str, 0, strlen(str)-1)) {
        printf("The string belongs to the language defined by the CFG.\n");
    } else {
        printf("The string does not belong to the language defined by the CFG.\n");
    }
    return 0;
}
int is_valid(char str[MAX_LEN], int start, int end) {
    if (start > end) {
        return 1;
    }
    if (str[start] == '0' || str[start] == '1') {
        for (int i = start+1; i <= end; i++) {
            if (str[i] == '0' || str[i] == '1') {
                if (is_valid(str, start+1, i-1) && is_valid(str, i, end)) {
                    return 1;
                }
            }
        }
    }
    if (end-start >= 2 && str[start] == '1' && str[start+1] == '0' && str[end] == '1') {
        if (is_valid(str, start+2, end-1)) {
            return 1;
        }
    }
    return 0;
}

