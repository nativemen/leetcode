#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        if (numCourses == 1 || prerequisites.size() <= 1) {
            return true;
        }

        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);

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

        int count = 0;

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            for (const auto &it : adj[course]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return count == numCourses;
    }
};

class Solution {
    bool hasCycle(vector<vector<int>> &adj, vector<int> &visited, int i) {
        if (visited[i] == 1) {
            return true;
        }

        if (visited[i] == 2) {
            return false;
        }

        visited[i] = 1;

        for (const auto &neighbor : adj[i]) {
            if (hasCycle(adj, visited, neighbor)) {
                return true;
            }
        }

        visited[i] = 2;

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        if (numCourses == 1 || prerequisites.size() <= 1) {
            return true;
        }

        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(adj, visited, i)) {
                return false;
            }
        }

        return true;
    }
};