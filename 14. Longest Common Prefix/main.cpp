#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        size_t prefixLen = strs[0].size();

        for (const auto &str : strs) {
            size_t j = 0;
            while (j < prefixLen && strs[0][j] == str[j]) {
                j++;
            }

            prefixLen = j;
            if (prefixLen == 0) {
                break;
            }
        }

        return strs[0].substr(0, prefixLen);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        size_t prefixLen = strs[0].size();

        for (const auto &str : strs) {
            while (prefixLen > 0 && strs[0].substr(0, prefixLen) != str.substr(0, prefixLen)) {
                prefixLen--;
            }

            if (prefixLen == 0) {
                break;
            }
        }

        return strs[0].substr(0, prefixLen);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        size_t prefixLen = strs[0].size();
        size_t size = strs.size();

        string answer;
        for (size_t i = 0; i < prefixLen; i++) {
            size_t j = 0;
            while (j < size && i < strs[j].size() && strs[0][i] == strs[j][i]) {
                j++;
            }

            if (j != size) {
                break;
            }

            answer.push_back(strs[0][i]);
        }

        return answer;
    }
};