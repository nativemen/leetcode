#include <stdbool.h>
#include <stdio.h>

bool isInterleave(char *s1, char *s2, char *s3) {
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    int s3Len = strlen(s3);
    if (s1Len + s2Len != s3Len) {
        return false;
    }

    bool dp[s1Len + 1][s2Len + 1];
    for (int i = 0; i <= s1Len; i++) {
        for (int j = 0; j <= s2Len; j++) {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;

    for (int i = 0; i <= s1Len; i++) {
        for (int j = 0; j <= s2Len; j++) {
            if (i == 0 && j > 0) {
                dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
            } else if (j == 0 && i > 0) {
                dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
            } else if (i > 0 && j > 0) {
                dp[i][j] = (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) ||
                           (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }
    }

    return dp[s1Len][s2Len];
}

bool isInterleave(char *s1, char *s2, char *s3) {
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    int s3Len = strlen(s3);
    if (s1Len + s2Len != s3Len) {
        return false;
    }

    bool dp[s1Len + 1][s2Len + 1];
    for (int i = 0; i <= s1Len; i++) {
        for (int j = 0; j <= s2Len; j++) {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;

    for (int i = 0; i <= s1Len; i++) {
        for (int j = 0; j <= s2Len; j++) {
            if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }

            if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
    }

    return dp[s1Len][s2Len];
}

#define ARRAY_SIZE 101

static int dp[ARRAY_SIZE][ARRAY_SIZE];

static bool checkInterleave(char *s1, char *s2, char *s3, int s1Len, int s2Len, int s3Len, int i, int j, int k) {
    if (i == s1Len && j == s2Len && k == s3Len) {
        return true;
    }

    if (k == s3Len) {
        return false;
    }

    if (dp[i][j] != -1) {
        return dp[i][j] == 1;
    }

    bool cond1 = false;
    bool cond2 = false;

    if (i < s1Len && k < s3Len && s1[i] == s3[k]) {
        dp[i][j] = checkInterleave(s1, s2, s3, s1Len, s2Len, s3Len, i + 1, j, k + 1);
        cond1 = dp[i][j];
    }

    if (j < s2Len && k < s3Len && s2[j] == s3[k]) {
        dp[i][j] = checkInterleave(s1, s2, s3, s1Len, s2Len, s3Len, i, j + 1, k + 1);
        cond2 = dp[i][j];
    }

    return cond1 || cond2;
}

bool isInterleave(char *s1, char *s2, char *s3) {
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    int s3Len = strlen(s3);

    if (s1Len + s2Len != s3Len) {
        return false;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            dp[i][j] = -1;
        }
    }

    return checkInterleave(s1, s2, s3, s1Len, s2Len, s3Len, 0, 0, 0);
}

bool isInterleave(char *s1, char *s2, char *s3) {
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    int s3Len = strlen(s3);

    if (s1Len + s2Len != s3Len) {
        return false;
    }

    bool dp[s2Len + 1];
    for (int j = 0; j <= s2Len; j++) {
        dp[j] = false;
    }

    dp[0] = true;

    for (int i = 0; i <= s1Len; i++) {
        for (int j = 0; j <= s2Len; j++) {
            if (i == 0 && j > 0) {
                dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
            } else if (j == 0 && i > 0) {
                dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            } else if (i > 0 && j > 0) {
                dp[j] = (dp[j] && (s1[i - 1] == s3[i + j - 1])) || (dp[j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }
    }

    return dp[s2Len];
}