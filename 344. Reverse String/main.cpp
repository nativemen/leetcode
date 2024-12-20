#include <algorithm>
#include <ranges>
#include <stack>
#include <vector>

using std::reverse;
using std::stack;
using std::swap;
using std::vector;

class Solution {
public:
    void reverseString(vector<char> &s) {
        std::ranges::reverse(s);
    }
};

class Solution {
public:
    void reverseString(vector<char> &s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

class Solution {
public:
    void reverseString(vector<char> &s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

class Solution {
public:
    void reverseString(vector<char> &s) {
        stack<char> stk;

        for (const auto &c : s) {
            stk.push(c);
        }

        for (int i = 0; i < s.size(); i++) {
            s[i] = stk.top();
            stk.pop();
        }
    }
};