#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    void dfs(unordered_map<string, vector<pair<string, double>>> &maps,
             unordered_set<string> &visited,
             string &src,
             string &dest,
             double value,
             double &answer) {
        visited.insert(src);

        if (src == dest) {
            answer = value;
            return;
        }

        for (auto &pair : maps[src]) {
            if (!visited.contains(pair.first)) {
                dfs(maps, visited, pair.first, dest, value * pair.second, answer);
            }
        }

        visited.erase(visited.find(src));
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        unordered_map<string, vector<pair<string, double>>> maps;

        for (int i = 0; i < equations.size(); i++) {
            maps[equations[i][0]].push_back({equations[i][1], values[i]});
            maps[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> result;

        for (int i = 0; i < queries.size(); i++) {
            if (!maps.contains(queries[i][0]) || !maps.contains(queries[i][1])) {
                result.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double answer = -1.0;
            dfs(maps, visited, queries[i][0], queries[i][1], 1.0, answer);

            result.push_back(answer);
        }

        return result;
    }
};

class Solution {
    unordered_map<string, pair<string, double>> maps;

    pair<string, double> find(string x) {
        if (maps.find(x) == maps.end()) {
            maps[x] = {x, 1.0};
        }

        auto [y, valueY] = maps[x];

        if (y != x) {
            auto [z, valueZ] = find(y);
            maps[x] = {z, valueY * valueZ};
        }

        return maps[x];
    }

    void unions(string u, string v, double value) {
        auto [rootX, valueX] = find(u);
        auto [rootY, valueY] = find(v);

        if (rootX != rootY) {
            maps[rootX] = {rootY, value * valueY / valueX};
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        size_t size = equations.size();

        for (size_t i = 0; i < size; i++) {
            unions(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> result;

        for (auto &query : queries) {
            string u = query[0];
            string v = query[1];

            if (!maps.contains(u) || !maps.contains(v)) {
                result.push_back(-1.0);
                continue;
            }

            auto [rootU, valueU] = find(u);
            auto [rootV, valueV] = find(v);

            if (rootU != rootV) {
                result.push_back(-1.0);
            } else {
                result.push_back(valueU / valueV);
            }
        }

        return result;
    }
};