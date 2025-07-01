#include <vector>

using namespace std;

class Solution {
    vector<int> parent;

    void init(int size) {
        parent.resize(size);

        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        init(isConnected.size());

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] == 1) {
                    unionSet(i, j);
                }
            }
        }

        int count = 0;

        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i) {
                count++;
            }
        }

        return count;
    }
};

class Solution {
    void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int current) {
        visited[current] = 1;

        for (int j = 0; j < isConnected[current].size(); j++) {
            if (isConnected[current][j] == 1 && visited[j] == 0) {
                dfs(isConnected, visited, j);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int count = 0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (visited[i] == 0) {
                dfs(isConnected, visited, i);
                count++;
            }
        }

        return count;
    }
};