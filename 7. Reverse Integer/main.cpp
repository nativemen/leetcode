#include <algorithm>
#include <climits>
#include <stdexcept>
#include <string>

using std::reverse;
using std::string;
using std::to_string;

class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int digit = x % 10;
            if (((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) ||
                ((result < INT_MIN / 10) || (result == INT_MIN / 10 && digit < INT_MIN % 10))) {
                return false;
            }

            result = result * 10 + digit;
            x /= 10;
        }

        return result;
    }
};

class Solution {
public:
    int reverse(int x) {
        int offset = 0;
        string str = to_string(x);
        if (x < 0) {
            offset = 1;
        }
        std::reverse(str.begin() + offset, str.end());

        int result = 0;
        try {
            result = stoi(str);
        } catch (const std::invalid_argument &e) {
            return 0;
        } catch (const std::out_of_range &e) {
            return 0;
        }

        return result;
    }
};