#include <string>
#include <vector>

using namespace std;

class Solution {
    static constexpr int ARRAY_SIZE = 101;
    vector<vector<int>> dp = vector<vector<int>>(ARRAY_SIZE, vector<int>(ARRAY_SIZE, -1));

    bool checkIterleave(string s1, string s2, string s3, int i, int j, int k) {
        int s1Len = s1.size();
        int s2Len = s2.size();
        int s3Len = s3.size();

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
            dp[i][j] = checkIterleave(s1, s2, s3, i + 1, j, k + 1);
            cond1 = dp[i][j];
        }

        if (j < s2Len && k < s3Len && s2[j] == s3[k]) {
            dp[i][j] = checkIterleave(s1, s2, s3, i, j + 1, k + 1);
            cond2 = dp[i][j];
        }

        return cond1 || cond2;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1Len = s1.size();
        int s2Len = s2.size();
        int s3Len = s3.size();

        if (s1Len + s2Len != s3Len) {
            return false;
        }

        return checkIterleave(s1, s2, s3, 0, 0, 0);
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1Len = s1.size();
        int s2Len = s2.size();
        int s3Len = s3.size();

        if (s1Len + s2Len != s3Len) {
            return false;
        }

        vector<vector<bool>> dp = vector<vector<bool>>(s1Len + 1, vector<bool>(s2Len + 1, false));
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
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1Len = s1.size();
        int s2Len = s2.size();
        int s3Len = s3.size();

        if (s1Len + s2Len != s3Len) {
            return false;
        }

        vector<vector<bool>> dp = vector<vector<bool>>(s1Len + 1, vector<bool>(s2Len + 1, false));
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
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1Len = s1.size();
        int s2Len = s2.size();
        int s3Len = s3.size();

        if (s1Len + s2Len != s3Len) {
            return false;
        }

        vector<bool> dp = vector<bool>(s2Len + 1, false);
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
};