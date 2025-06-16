#include <queue>
#include <unordered_set>
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

class Solution {
    void dfs(vector<vector<int>> &rooms, int current, unordered_set<int> &visited) {
        if (visited.contains(current)) {
            return;
        }

        visited.insert(current);

        for (const auto &room : rooms[current]) {
            dfs(rooms, room, visited);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        unordered_set<int> visited;

        dfs(rooms, 0, visited);

        return visited.size() == rooms.size();
    }
};

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        queue<int> q;
        q.push(0);

        unordered_set<int> visited;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            visited.insert(current);

            for (const auto &room : rooms[current]) {
                if (!visited.contains(room)) {
                    q.push(room);
                }
            }
        }

        return visited.size() == rooms.size();
    }
};