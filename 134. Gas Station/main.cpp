#include <numeric>
#include <vector>

using std::accumulate;
using std::vector;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;

        for (size_t i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
        }

        if (total < 0) {
            return -1;
        }

        int tank = 0;
        int start = 0;

        for (size_t i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return start;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int tank = 0;
        int start = 0;

        for (size_t i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return (total < 0) ? (-1) : start;
    }
};