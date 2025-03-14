#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
public:
    bool isValid(string s) {
        vector<int> stack;

        for (const auto &c : s) {
            if (c == '{' || c == '[' || c == '(') {
                stack.push_back(c);
            } else {
                if (stack.empty() || (c == '}' && stack.back() != '{') || (c == ']' && stack.back() != '[') ||
                    (c == ')' && stack.back() != '(')) {
                    return false;
                }
                stack.pop_back();
            }
        }

        return stack.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;

        for (const auto &c : s) {
            if (c == '{' || c == '[' || c == '(') {
                stack.push(c);
            } else {
                if (stack.empty() || (c == '}' && stack.top() != '{') || (c == ']' && stack.top() != '[') ||
                    (c == ')' && stack.top() != '(')) {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.empty();
    }
};