#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        size_t sLen = s.size();
        size_t wordDictSize = wordDict.size();
        vector<bool> dp(sLen + 1, false);
        dp[0] = true;

        for (size_t i = 0; i <= sLen; i++) {
            for (size_t j = 0; j < wordDictSize; j++) {
                size_t wordLen = wordDict[j].size();
                if (dp[i] && s.compare(i, wordLen, wordDict[j]) == 0) {
                    dp[i + wordLen] = true;
                }
            }
        }

        return dp[sLen];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        size_t sLen = s.size();
        size_t wordDictSize = wordDict.size();
        vector<bool> dp(sLen + 1, false);
        dp[0] = true;

        for (size_t i = 0; i <= sLen; i++) {
            if (!dp[i]) {
                continue;
            }

            for (size_t j = 0; j < wordDictSize; j++) {
                size_t wordLen = wordDict[j].size();
                if (s.compare(i, wordLen, wordDict[j]) == 0) {
                    dp[i + wordLen] = true;
                }
            }
        }

        return dp[sLen];
    }
};