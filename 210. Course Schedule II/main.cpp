#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for (const auto &prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
            indegree[prerequisite[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);

            for (const auto &neighbor : adj[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (result.size() != numCourses) {
            result.clear();
        } else {
            reverse(result.begin(), result.end());
        }

        return result;
    }
};

class Solution {
    bool hasCycle(vector<vector<int>> &adj, vector<int> &visited, vector<int> &result, int index) {
        if (visited[index] == 1) {
            return true;
        }

        if (visited[index] == 2) {
            return false;
        }

        visited[index] = 1;

        for (const auto &neighbor : adj[index]) {
            if (hasCycle(adj, visited, result, neighbor)) {
                return true;
            }
        }

        visited[index] = 2;
        result.push_back(index);

        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (const auto &prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<int> visited(numCourses);
        vector<int> result;

        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(adj, visited, result, i)) {
                result.clear();
                return result;
            }
        }

        return result;
    }
};