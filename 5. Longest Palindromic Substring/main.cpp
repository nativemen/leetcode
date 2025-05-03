#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= 1; j++) {
                int left = i;
                int right = i + j;

                while (left >= 0 && right < len && s[left] == s[right]) {
                    left--;
                    right++;
                }

                int curLen = right - left - 1;
                if (curLen > maxLen) {
                    maxLen = curLen;
                    start = left + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};