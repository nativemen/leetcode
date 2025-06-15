#include <vector>


using namespace std;

class Solution {
    void dfs(vector<vector<int>> &rooms, int index, vector<bool> &visited) {
        if (index < 0 || index >= rooms.size() || visited[index]) {
            return;
        }

        visited[index] = true;

        for (const auto &room : rooms[index]) {
            dfs(rooms, room, visited);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        vector<bool> visited(rooms.size(), false);

        dfs(rooms, 0, visited);

        for (const auto &status : visited) {
            if (!status) {
                return false;
            }
        }

        return true;
    }
};