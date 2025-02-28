#include <vector>

using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur(rowIndex + 1);
        vector<int> prev(rowIndex + 1);

        for (int i = 0; i < rowIndex + 1; i++) {
            cur[0] = 1;
            cur[i] = 1;
            for (int j = 1; j < rowIndex; j++) {
                cur[j] = prev[j - 1] + prev[j];
            }
            vector<int> temp = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1);
        long long val = 1;

        for (int i = 0; i < rowIndex + 1; i++) {
            row[i] = val;
            val = val * (rowIndex - i) / (i + 1);
        }

        return row;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;

        for (int i = 0; i < rowIndex + 1; i++) {
            triangle.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }

        return triangle[rowIndex];
    }
};