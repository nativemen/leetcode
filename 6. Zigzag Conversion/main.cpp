#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> rows(numRows);
        int level = 0;
        int direction = -1;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            rows[level].push_back(s[i]);
            if (level % (numRows - 1) == 0) {
                direction *= -1;
            }
            level += direction;
        }

        string result;
        for (const auto &row : rows) {
            result.append(row);
        }

        return result;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        string result;
        int size = s.size();

        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < size; j += 2 * (numRows - 1)) {
                result.push_back(s[j]);

                if (i > 0 && i < numRows - 1 && j + 2 * (numRows - 1) - 2 * i < size) {
                    result.push_back(s[j + 2 * (numRows - 1) - 2 * i]);
                }
            }
        }

        return result;
    }
};