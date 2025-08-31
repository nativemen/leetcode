#include <stdbool.h>
#include <stdio.h>

int longestCommonSubsequence(char *text1, char *text2) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);

    int dp[len1][len2];
    dp[0][0] = (text1[0] == text2[0]) ? 1 : 0;

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (text1[i] == text2[j]) {
                dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i - 1][j - 1] + 1;
            } else {
                int first = (i == 0) ? 0 : dp[i - 1][j];
                int second = (j == 0) ? 0 : dp[i][j - 1];

                dp[i][j] = (first >= second) ? first : second;
            }
        }
    }

    return dp[len1 - 1][len2 - 1];
}