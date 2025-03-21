#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::sort;
using std::vector;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        size_t index = 0;

        for (const auto &interval : intervals) {
            if (intervals[index][1] < interval[0]) {
                index++;
                intervals[index][0] = interval[0];
                intervals[index][1] = interval[1];
            } else {
                intervals[index][1] = max(intervals[index][1], interval[1]);
            }
        }

        return vector<vector<int>>(intervals.begin(), intervals.begin() + index + 1);
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> result;

        for (size_t i = 0; i < intervals.size(); i++) {
            if (newInterval[1] < intervals[i][0]) {
                result.push_back(newInterval);
                result.insert(result.end(), intervals.begin() + i, intervals.end());

                return result;
            } else if (newInterval[0] > intervals[i][1]) {
                result.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        result.push_back(newInterval);

        return result;
    }
};