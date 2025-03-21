#include <algorithm>
#include <vector>

using std::max;
using std::sort;
using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] < b[0]);
        });

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int index = 0;

        for (const auto &interval : intervals) {
            if (result[index][1] < interval[0]) {
                index++;
                result.push_back(interval);
            } else {
                result[index][1] = max(result[index][1], interval[1]);
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int index = 0;

        for (const auto &interval : intervals) {
            if (result[index][1] < interval[0]) {
                index++;
                result.push_back(interval);
            } else {
                result[index][1] = max(result[index][1], interval[1]);
            }
        }

        return result;
    }
};