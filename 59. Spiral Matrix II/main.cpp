#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int num = 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                result[top][i] = num++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result[i][right] = num++;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result[bottom][i] = num++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result[i][left] = num++;
                }
                left++;
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int num = 1;
        int total = n * n;

        while (num <= total) {
            for (int i = left; i <= right; i++) {
                result[top][i] = num++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result[i][right] = num++;
            }
            right--;

            for (int i = right; i >= left; i--) {
                result[bottom][i] = num++;
            }
            bottom--;

            for (int i = bottom; i >= top; i--) {
                result[i][left] = num++;
            }
            left++;
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int num = 1;
        int total = n * n;
        int direction = 1;

        while (num <= total) {
            switch (direction) {
                case 1: {
                    for (int i = left; i <= right; i++) {
                        result[top][i] = num++;
                    }
                    top++;
                    direction = 2;
                    break;
                }
                case 2: {
                    for (int i = top; i <= bottom; i++) {
                        result[i][right] = num++;
                    }
                    right--;
                    direction = 3;
                    break;
                }
                case 3: {
                    for (int i = right; i >= left; i--) {
                        result[bottom][i] = num++;
                    }
                    bottom--;
                    direction = 4;
                    break;
                }
                default: {
                    for (int i = bottom; i >= top; i--) {
                        result[i][left] = num++;
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