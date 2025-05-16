#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<string> result;
    string s;

    void backtrack(int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(s);
            return;
        }

        if (left > 0) {
            s.push_back('(');
            backtrack(left - 1, right);
            s.pop_back();
        }

        if (right > left) {
            s.push_back(')');
            backtrack(left, right - 1);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        backtrack(n, n);

        return result;
    }
};

class Solution {
    void backtrack(vector<string> &result, string s, int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(s);
            return;
        }

        if (left > 0) {
            backtrack(result, s + '(', left - 1, right);
        }

        if (right > left) {
            backtrack(result, s + ')', left, right - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        backtrack(result, "", n, n);

        return result;
    }
};