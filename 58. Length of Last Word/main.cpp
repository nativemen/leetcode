#include <string>

using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        char next = ' ';

        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (next != ' ' && *it == ' ') {
                break;
            }

            if (*it != ' ') {
                count++;
            }

            next = *it;
        }

        return count;
    }
};