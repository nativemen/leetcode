#include <algorithm>
#include <string>

using std::reverse;
using std::string;

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        for (int i = 0; i < len; i += 2 * k) {
            int min = k > len - i ? len - i : k;
            for (int j = 0; j < (min + 1) / 2; j++) {
                char temp = s[i + j];
                s[i + j] = s[i + min - 1 - j];
                s[i + min - 1 - j] = temp;
            }
        }

        return s;
    }
};

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        for (int i = 0; i < len; i += 2 * k) {
            if (i + k < len) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }

        return s;
    }
};