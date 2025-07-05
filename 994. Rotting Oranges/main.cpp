#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        deque<pair<int, int>> q;
        int fresh = 0;
        int rowSize = grid.size();
        int colSize = grid[0].size();

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push_back({i, j});
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        int minutes = -1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop_front();

                if (x > 0 && grid[x - 1][y] == 1) {
                    q.push_back({x - 1, y});
                    grid[x - 1][y] = 2;
                    fresh--;
                }

                if (x < rowSize - 1 && grid[x + 1][y] == 1) {
                    q.push_back({x + 1, y});
                    grid[x + 1][y] = 2;
                    fresh--;
                }

                if (y > 0 && grid[x][y - 1] == 1) {
                    q.push_back({x, y - 1});
                    grid[x][y - 1] = 2;
                    fresh--;
                }

                if (y < colSize - 1 && grid[x][y + 1] == 1) {
                    q.push_back({x, y + 1});
                    grid[x][y + 1] = 2;
                    fresh--;
                }
            }

            minutes++;
        }

        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }
};