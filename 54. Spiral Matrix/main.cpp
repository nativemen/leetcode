#include <vector>

using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        int left = 0;
        int right = colNum - 1;
        int top = 0;
        int bottom = rowNum - 1;
        vector<int> result;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        int left = 0;
        int right = colNum - 1;
        int top = 0;
        int bottom = rowNum - 1;
        int direction = 1;
        vector<int> result;

        while (result.size() < rowNum * colNum) {
            switch (direction) {
                case 1: {
                    for (int i = left; i <= right; i++) {
                        result.push_back(matrix[top][i]);
                    }
                    top++;
                    direction = 2;
                    break;
                }
                case 2: {
                    for (int i = top; i <= bottom; i++) {
                        result.push_back(matrix[i][right]);
                    }
                    right--;
                    direction = 3;
                    break;
                }
                case 3: {
                    for (int i = right; i >= left; i--) {
                        result.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                    direction = 4;
                    break;
                }
                case 4: {
                    for (int i = bottom; i >= top; i--) {
                        result.push_back(matrix[i][left]);
                    }
                    left++;
                    direction = 1;
                    break;
                }
            }
        }

        return result;
    }
};