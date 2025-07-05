#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        deque<pair<int, int>> q;

        q.push_back({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '*';

        int count = 0;
        int rowSize = maze.size();
        int colSize = maze[0].size();

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop_front();

                if (count > 0 && (x == 0 || x == rowSize - 1 || y == 0 || y == colSize - 1)) {
                    return count;
                }

                if (x > 0 && maze[x - 1][y] == '.') {
                    q.push_back({x - 1, y});
                    maze[x - 1][y] = '*';
                }

                if (x < rowSize - 1 && maze[x + 1][y] == '.') {
                    q.push_back({x + 1, y});
                    maze[x + 1][y] = '*';
                }

                if (y > 0 && maze[x][y - 1] == '.') {
                    q.push_back({x, y - 1});
                    maze[x][y - 1] = '*';
                }

                if (y < colSize - 1 && maze[x][y + 1] == '.') {
                    q.push_back({x, y + 1});
                    maze[x][y + 1] = '*';
                }
            }

            count++;
        }

        return -1;
    }
};

class Solution {
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        queue<pair<int, int>> q;

        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '*';

        int count = 0;
        int rowSize = maze.size();
        int colSize = maze[0].size();

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                if (count > 0 && (x == 0 || x == rowSize - 1 || y == 0 || y == colSize - 1)) {
                    return count;
                }

                if (x > 0 && maze[x - 1][y] == '.') {
                    q.push({x - 1, y});
                    maze[x - 1][y] = '*';
                }

                if (x < rowSize - 1 && maze[x + 1][y] == '.') {
                    q.push({x + 1, y});
                    maze[x + 1][y] = '*';
                }

                if (y > 0 && maze[x][y - 1] == '.') {
                    q.push({x, y - 1});
                    maze[x][y - 1] = '*';
                }

                if (y < colSize - 1 && maze[x][y + 1] == '.') {
                    q.push({x, y + 1});
                    maze[x][y + 1] = '*';
                }
            }

            count++;
        }

        return -1;
    }
};