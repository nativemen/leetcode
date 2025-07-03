#include <math.h>
#include <vector>

using namespace std;

class Solution {
    int count;

    void dfs(vector<vector<int>> &maps, vector<int> &visited, int from) {
        visited[from] = 1;

        for (const auto &neighbor : maps[from]) {
            if (visited[abs(neighbor)] == 0) {
                if (neighbor > 0) {
                    count++;
                }

                dfs(maps, visited, abs(neighbor));
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<int>> maps(n);

        for (const auto &c : connections) {
            maps[c[0]].push_back(c[1]);
            maps[c[1]].push_back(-c[0]);
        }

        vector<int> visited(n, 0);

        dfs(maps, visited, 0);

        return count;
    }
};