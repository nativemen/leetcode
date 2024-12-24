#include <string>

using std::string;

class Solution {
public:
    int myAtoi(string s) {
        int start = 0;
        while (s[start] == ' ') {
            start++;
        }

        long long sign = 1;
        if (s[start] == '-') {
            sign = -1;
            start++;
        } else if (s[start] == '+') {
            start++;
        }

        long long num = 0;
        for (const auto &c : s.substr(start)) {
            if (!isdigit(c)) {
                break;
            }

            num = num * 10 + sign * (c - '0');
            if (num > INT_MAX) {
                return INT_MAX;
            } else if (num < INT_MIN) {
                return INT_MIN;
            }
        }
        return (int)num;
    }
};

class Solution {
public:
    int myAtoi(string s) {
        int start = 0;
        while (s[start] == ' ') {
            start++;
        }

        int sign = 1;
        if (s[start] == '-') {
            sign = -1;
            start++;
        } else if (s[start] == '+') {
            start++;
        }

        int num = 0;
        for (const auto &c : s.substr(start)) {
            if (!isdigit(c)) {
                break;
            }

            int digit = sign * (int)(c - '0');
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return INT_MAX;
            } else if (num < INT_MIN / 10 || (num == INT_MIN / 10 && digit < INT_MIN % 10)) {
                return INT_MIN;
            }
            num = num * 10 + digit;
        }
        return num;
    }
};