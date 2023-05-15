#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkString(char *str)
{
    int len = strlen(str);
    int i, j, k;
    int dp[len][len];
    for (i = 0; i < len; i++) {
        if (str[i] == '0' || str[i] == '1') {
            dp[i][i] = 0;
        } else {
            dp[i][i] = 1;
        }
    }
    for (k = 2; k <= len; k++) {
        for (i = 0; i < len - k + 1; i++) {
            j = i + k - 1;
            dp[i][j] = 0;
            if (str[i] == '0' && str[j] == '1' && k == 2) {
                dp[i][j] = 1;
            }
            for (int m = i; m < j; m++) {
                if (dp[i][m] && dp[m + 1][j]) {
                    dp[i][j] = 1;
                    break;
                }
            }
        }
    }
    return dp[0][len - 1];
}
int main()
{
    char str[100];
    printf("Enter a string to check whether it belongs to the language defined by the CFG: ");
    scanf("%s", str);
    if (checkString(str)) {
        printf("%s belongs to the language defined by the CFG.\n", str);
    } else {
        printf("%s does not belong to the language defined by the CFG.\n", str);
    }
    return 0;
}

