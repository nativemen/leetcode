#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        if (x == 0) {
            return true;
        }

        vector<int> digit;

        while (x != 0) {
            digit.push_back(x % 10);
            x /= 10;
        }

        int left = 0;
        int right = digit.size() - 1;

        while (left < right) {
            if (digit[left++] != digit[right--]) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        if (x == 0) {
            return true;
        }

        int reverse = 0;
        int original = x;

        while (x != 0) {
            reverse *= 10;
            reverse += x % 10;
            x /= 10;
        }

        return original == reverse;
    }
};