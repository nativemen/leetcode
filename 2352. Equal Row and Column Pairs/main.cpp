#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int count = 0;

        for (size_t c = 0; c < colSize; c++) {
            vector<int> column;
            for (size_t r = 0; r < rowSize; r++) {
                column.push_back(grid[r][c]);
            }

            for (size_t r = 0; r < rowSize; r++) {
                if (grid[r] == column) {
                    count++;
                }
            }
        }

        return count;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int count = 0;
        map<vector<int>, int> maps;

        for (size_t i = 0; i < rowSize; i++) {
            maps[grid[i]]++;
        }

        for (size_t j = 0; j < colSize; j++) {
            vector<int> column;
            for (size_t i = 0; i < rowSize; i++) {
                column.push_back(grid[i][j]);
            }

            if (maps.contains(column)) {
                count += maps[column];
            }
        }

        return count;
    }
};

class Solution {
    static constexpr int PRIME_BASE = 301;
    static constexpr int PRIME_MOD = 100001;

public:
    int equalPairs(vector<vector<int>> &grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        vector<int> rowHash(rowSize, 0);
        vector<int> colHash(colSize, 0);

        for (size_t r = 0; r < rowSize; r++) {
            int hash = 0;
            for (size_t c = 0; c < colSize; c++) {
                hash = (hash * PRIME_BASE + grid[r][c]) % PRIME_MOD;
            }
            rowHash[r] = hash;
        }

        for (size_t c = 0; c < colSize; c++) {
            int hash = 0;
            for (size_t r = 0; r < rowSize; r++) {
                hash = (hash * PRIME_BASE + grid[r][c]) % PRIME_MOD;
            }
            colHash[c] = hash;
        }

        int count = 0;

        for (size_t r = 0; r < rowSize; r++) {
            for (size_t c = 0; c < colSize; c++) {
                if (rowHash[r] == colHash[c]) {
                    count++;
                }
            }
        }

        return count;
    }
};