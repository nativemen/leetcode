#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        int num = 0;
        int sign = 1;
        int result = 0;

        for (const auto &c : s) {
            if (isdigit(c)) {
                num *= 10;
                num += c - '0';
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                stk.push_back(result);
                stk.push_back(sign);
                num = 0;
                sign = 1;
                result = 0;
            } else if (c == ')') {
                result += sign * num;
                result *= stk.back();
                stk.pop_back();
                result += stk.back();
                stk.pop_back();
                num = 0;
                sign = 1;
            }
        }

        return result + sign * num;
    }
};

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        int sign = 1;
        int result = 0;

        for (const auto &c : s) {
            if (isdigit(c)) {
                num *= 10;
                num += c - '0';
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                stk.push(result);
                stk.push(sign);
                num = 0;
                sign = 1;
                result = 0;
            } else if (c == ')') {
                result += sign * num;
                result *= stk.top();
                stk.pop();
                result += stk.top();
                stk.pop();
                num = 0;
                sign = 1;
            }
        }

        return result + sign * num;
    }
};