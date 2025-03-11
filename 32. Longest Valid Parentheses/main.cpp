#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using std::max;
using std::stack;
using std::string;
using std::vector;

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

class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        if (size == 0) {
            return 0;
        }

        int result = 0;
        stack<int> stacks;
        stacks.push(-1);

        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                stacks.push(i);
            } else {
                stacks.pop();
                if (stacks.empty()) {
                    stacks.push(i);
                } else {
                    result = max(result, i - stacks.top());
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        if (size == 0) {
            return 0;
        }

        int result = 0;
        vector<int> stacks;
        stacks.push_back(-1);

        for (int i = 0; i < size; i++) {
            if (s[i] == '(') {
                stacks.push_back(i);
            } else {
                stacks.pop_back();
                if (stacks.empty()) {
                    stacks.push_back(i);
                } else {
                    result = max(result, i - stacks.back());
                }
            }
        }

        return result;
    }
};