#include <algorithm>
#include <string>

using std::reverse;
using std::string;

struct Solution;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }

            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        for (auto &c : s) {
            c = std::tolower(c);
        }
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !std::isalnum(c); }), s.end());
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        return reversed == s;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        for (auto &c : s) {
            if (std::isalnum(c)) {
                clean += std::tolower(c);
            }
        }

        string reversed = clean;
        reverse(reversed.begin(), reversed.end());
        return reversed == clean;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        for (auto &c : s) {
            if (std::isalnum(c)) {
                clean += std::tolower(c);
            }
        }

        size_t len = clean.size();
        for (size_t i = 0; i < len / 2; i++) {
            if (clean[i] != clean[len - 1 - i]) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        return isEqual(s, 0, s.size() - 1);
    }

    bool isEqual(string &s, int left, int right) {
        if (left >= right) {
            return true;
        }

        if (!std::isalnum(s[left])) {
            return isEqual(s, left + 1, right);
        }

        if (!std::isalnum(s[right])) {
            return isEqual(s, left, right - 1);
        }

        if (tolower(s[left]) == tolower(s[right])) {
            return isEqual(s, left + 1, right - 1);
        }

        return false;
    }
};