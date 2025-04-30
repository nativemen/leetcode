#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rowSize = matrix.size();
        if (rowSize <= 0) {
            return false;
        }

        int colSize = matrix[0].size();
        if (colSize <= 0) {
            return false;
        }

        int left = 0;
        int right = rowSize * colSize - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int row = mid / colSize;
            int col = mid % colSize;

            if (target < matrix[row][col]) {
                right = mid - 1;
            } else if (target > matrix[row][col]) {
                left = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};