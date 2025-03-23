#include <vector>

using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        size_t rowSize = matrix.size();
        size_t colSize = matrix[0].size();
        vector<bool> rows(rowSize, false);
        vector<bool> cols(colSize, false);

        for (size_t i = 0; i < rowSize; i++) {
            for (size_t j = 0; j < colSize; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (size_t i = 0; i < rowSize; i++) {
            if (rows[i]) {
                for (size_t j = 0; j < colSize; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (size_t j = 0; j < colSize; j++) {
            if (cols[j]) {
                for (size_t i = 0; i < rowSize; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        size_t rowSize = matrix.size();
        size_t colSize = matrix[0].size();
        vector<bool> rows(rowSize, false);
        vector<bool> cols(colSize, false);

        for (size_t i = 0; i < rowSize; i++) {
            for (size_t j = 0; j < colSize; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (size_t i = 0; i < rowSize; i++) {
            for (size_t j = 0; j < colSize; j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        size_t rowSize = matrix.size();
        size_t colSize = matrix[0].size();
        bool firstRowHasZero = false;
        bool firstColHasZero = false;

        for (size_t i = 0; i < rowSize; i++) {
            for (size_t j = 0; j < colSize; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                    if (i == 0) {
                        firstRowHasZero = true;
                    }

                    if (j == 0) {
                        firstColHasZero = true;
                    }
                }
            }
        }

        for (size_t i = 1; i < rowSize; i++) {
            for (size_t j = 1; j < colSize; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowHasZero) {
            for (size_t j = 0; j < colSize; j++) {
                matrix[0][j] = 0;
            }
        }

        if (firstColHasZero) {
            for (size_t i = 0; i < rowSize; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        size_t rowSize = matrix.size();
        size_t colSize = matrix[0].size();
        bool firstRowHasZero = false;
        bool firstColHasZero = false;

        for (size_t j = 0; j < colSize; j++) {
            if (matrix[0][j] == 0) {
                firstRowHasZero = true;
            }
        }

        for (size_t i = 0; i < rowSize; i++) {
            if (matrix[i][0] == 0) {
                firstColHasZero = true;
            }
        }

        for (size_t i = 1; i < rowSize; i++) {
            for (size_t j = 1; j < colSize; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (size_t i = 1; i < rowSize; i++) {
            if (matrix[i][0] == 0) {
                for (size_t j = 1; j < colSize; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (size_t j = 1; j < colSize; j++) {
            if (matrix[0][j] == 0) {
                for (size_t i = 1; i < rowSize; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowHasZero) {
            for (size_t j = 0; j < colSize; j++) {
                matrix[0][j] = 0;
            }
        }

        if (firstColHasZero) {
            for (size_t i = 0; i < rowSize; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};