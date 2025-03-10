#include <algorithm>
#include <string>

using std::max;
using std::string;

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int left = 0;
        int right = 0;

        for (auto it = s.begin(); it != s.end(); it++) {
            if (*it == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                result = max(result, left + right);
            } else if (left < right) {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;

        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (*it == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                result = max(result, left + right);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return result;
    }
};