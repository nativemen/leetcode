#include <algorithm>
#include <string>

using std::reverse;
using std::string;

class Solution {
public:
    static bool isEqual(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left += 1;
            right -= 1;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return Solution::isEqual(s, left + 1, right) || Solution::isEqual(s, left, right - 1);
            }

            left += 1;
            right -= 1;
        }

        return true;
    }
};

class Solution {
public:
    static bool isEqual(string s, int left, int right, bool skipped) {
        while (left < right) {
            if (s[left] != s[right]) {
                if (skipped) {
                    return false;
                }

                return Solution::isEqual(s, left + 1, right, true) || Solution::isEqual(s, left, right - 1, true);
            }

            left += 1;
            right -= 1;
        }

        return true;
    }

    bool validPalindrome(string s) {
        return Solution::isEqual(s, 0, s.size() - 1, false);
    }
};

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                string origStr1 = s.substr(left + 1, right - left);
                string origStr2 = s.substr(left, right - left);
                string revStr1 = origStr1;
                string revStr2 = origStr2;
                std::reverse(revStr1.begin(), revStr1.end());
                std::reverse(revStr2.begin(), revStr2.end());

                return (origStr1 == revStr1) || (origStr2 == revStr2);
            }

            left += 1;
            right -= 1;
        }

        return true;
    }
};