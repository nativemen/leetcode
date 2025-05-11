#include <string>
#include <vector>

using namespace std;

class Solution {
    void backtrack(const char *digit, string &array, vector<string> &result, int len) {
        if (array.size() == len) {
            result.push_back(array);
            return;
        }

        const string maps[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int index = *digit - '2';

        for (int i = 0; i < maps[index].size(); i++) {
            array.push_back(maps[index][i]);
            backtrack(digit + 1, array, result, len);
            array.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if (digits.empty()) {
            return result;
        }

        string array;
        backtrack(digits.c_str(), array, result, digits.size());

        return result;
    }
};