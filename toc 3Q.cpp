#include <stdio.h>
#include <string.h>

int isBelongToLanguage(char str[], int start, int end);

int A(char str[], int start, int end) {
    int index = start;
    int res;

    if (index > end) {
        return 1;
    }

    if (str[index] == '0') {
        res = A(str, index + 1, end);
        if (res) {
            return 1;
        }
    }

    if (str[index] == '1') {
        res = A(str, index + 1, end);
        if (res) {
            return 1;
        }
    }

    return 0;
}

int S(char str[], int start, int end) {
    if (start == end && str[start] == '0') {
        return 0;
    }

    int i = start + 1;
    int res = A(str, i, end);

    if (str[start] == '0' && str[end] == '1' && res) {
        return 1;
    }

    return 0;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    int length = strlen(str);

    if (S(str, 0, length - 1)) {
        printf("String belongs to the language.\n");
    } else {
        printf("String does not belong to the language.\n");
    }

    return 0;
}
