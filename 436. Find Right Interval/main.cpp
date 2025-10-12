#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        vector<pair<int, int>> array;
        int intervalsSize = intervals.size();

        for (int i = 0; i < intervalsSize; i++) {
            array.push_back({intervals[i][0], i});
        }

        sort(array.begin(), array.end());

        vector<int> result(intervalsSize, -1);

        for (int i = 0; i < intervalsSize; i++) {
            int left = 0;
            int right = intervalsSize - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (intervals[i][1] <= array[mid].first) {
                    result[i] = array[mid].second;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return result;
    }
};