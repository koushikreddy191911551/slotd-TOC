#include <stdio.h>
#include <stdbool.h>

int main() {
    int state = 0;
    char input;
    bool accepted = false;
    
    printf("Enter a string: ");
    
    while ((input = getchar()) != '\n') {
        switch (state) {
            case 0:
                if (input == '0') {
                    state = 1;
                }
                break;
            case 1:
                if (input == '0') {
                    state = 1;
                } else if (input == '1') {
                    state = 2;
                } else {
                    state = 0;
                }
                break;
            case 2:
                if (input == '0' || input == '1') {
                    state = 2;
                } else {
                    state = 0;
                }
                break;
            default:
                break;
        }
    }
    
    if (state == 2) {
        accepted = true;
    }
    
    if (accepted) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }
    
    return 0;
}
