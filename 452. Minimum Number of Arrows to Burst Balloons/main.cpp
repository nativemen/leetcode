#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::sort;
using std::vector;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end());

        int index = 0;

        for (const auto &point : points) {
            if (points[index][1] < point[0]) {
                index++;
                points[index][0] = point[0];
                points[index][1] = point[1];
            } else {
                points[index][0] = max(points[index][0], point[0]);
                points[index][1] = min(points[index][1], point[1]);
            }
        }

        return index + 1;
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

        int count = 1;
        int preEnd = points[0][1];

        for (const auto &point : points) {
            if (point[0] > preEnd) {
                count++;
                preEnd = point[1];
            }
        }

        return count;
    }
};