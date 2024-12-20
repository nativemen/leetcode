#include <algorithm>
#include <vector>
#include <ranges>

using std::reverse;
using std::vector;
using std::swap;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        /* Transpose */
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = row; col < matrix[row].size(); col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }

        /* Flip left and right along the vertical center line */
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < (matrix[row].size() + 1) / 2; col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[row][matrix[row].size() - 1 - col];
                matrix[row][matrix[row].size() - 1 - col] = temp;
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        /* Transpose */
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = row; col < matrix[row].size(); col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        /* Flip left and right along the vertical center line */
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        /* Flip up and down with horizontal center line */
        std::ranges::reverse(matrix);

        /* Transpose */
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = row; col < matrix[row].size(); col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};