#include <stdbool.h>
#include <stdio.h>

bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    size_t sLen = strlen(s);
    bool dp[sLen + 1];

    for (size_t i = 0; i <= sLen; i++) {
        dp[i] = false;
    }

    dp[0] = true;

    for (size_t i = 0; i < sLen; i++) {
        for (size_t j = 0; j < wordDictSize; j++) {
            size_t len = strlen(wordDict[j]);
            if (dp[i] && strncmp(s + i, wordDict[j], len) == 0) {
                dp[i + len] = true;
            }
        }
    }

    return dp[sLen];
}

bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    size_t sLen = strlen(s);
    bool dp[sLen + 1];

    for (size_t i = 0; i <= sLen; i++) {
        dp[i] = false;
    }

    dp[0] = true;

    for (size_t i = 0; i < sLen; i++) {
        if (!dp[i]) {
            continue;
        }

        for (size_t j = 0; j < wordDictSize; j++) {
            size_t len = strlen(wordDict[j]);
            if (strncmp(s + i, wordDict[j], len) == 0) {
                dp[i + len] = true;
            }
        }
    }

    return dp[sLen];
}

bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    size_t sLen = strlen(s);
    bool dp[sLen + 1];

    for (size_t i = 0; i <= sLen; i++) {
        dp[i] = false;
    }

    dp[sLen] = true;

    for (size_t i = sLen; i > 0; i--) {
        if (!dp[i]) {
            continue;
        }

        for (size_t j = 0; j < wordDictSize; j++) {
            size_t len = strlen(wordDict[j]);
            if (i >= len && strncmp(s + i - len, wordDict[j], len) == 0) {
                dp[i - len] = true;
            }
        }
    }

    return dp[0];
}