#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        int dp[len1][len2];

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i - 1][j - 1] + 1;
                } else {
                    int first = (i == 0) ? 0 : dp[i - 1][j];
                    int second = (j == 0) ? 0 : dp[i][j - 1];
                    dp[i][j] = max(first, second);
                }
            }
        }

        return dp[len1 - 1][len2 - 1];
    }
};