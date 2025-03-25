#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stacks;

        for (const auto &token : tokens) {
            if (token == "+") {
                int num2 = stacks.back();
                stacks.pop_back();
                int num1 = stacks.back();
                stacks.pop_back();
                stacks.push_back(num1 + num2);
            } else if (token == "-") {
                int num2 = stacks.back();
                stacks.pop_back();
                int num1 = stacks.back();
                stacks.pop_back();
                stacks.push_back(num1 - num2);
            } else if (token == "*") {
                int num2 = stacks.back();
                stacks.pop_back();
                int num1 = stacks.back();
                stacks.pop_back();
                stacks.push_back(num1 * num2);
            } else if (token == "/") {
                int num2 = stacks.back();
                stacks.pop_back();
                int num1 = stacks.back();
                stacks.pop_back();
                stacks.push_back(num1 / num2);
            } else {
                stacks.push_back(stoi(token));
            }
        }

        return stacks.back();
    }
};

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stacks;

        for (const auto &token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                stacks.push_back(stoi(token));
            } else {
                int num2 = stacks.back();
                stacks.pop_back();
                int num1 = stacks.back();
                stacks.pop_back();

                if (token == "+") {
                    stacks.push_back(num1 + num2);
                } else if (token == "-") {
                    stacks.push_back(num1 - num2);
                } else if (token == "*") {
                    stacks.push_back(num1 * num2);
                } else if (token == "/") {
                    stacks.push_back(num1 / num2);
                }
            }
        }

        return stacks.back();
    }
};

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stacks;

        for (const auto &token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                stacks.push(stoi(token));
            } else {
                int num2 = stacks.top();
                stacks.pop();
                int num1 = stacks.top();
                stacks.pop();

                if (token == "+") {
                    stacks.push(num1 + num2);
                } else if (token == "-") {
                    stacks.push(num1 - num2);
                } else if (token == "*") {
                    stacks.push(num1 * num2);
                } else if (token == "/") {
                    stacks.push(num1 / num2);
                }
            }
        }

        return stacks.top();
    }
};