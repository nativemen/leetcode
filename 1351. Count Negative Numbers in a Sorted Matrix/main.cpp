#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>> &grid) {
        int count = 0;

        for (const auto &line : grid) {
            int left = 0;
            int right = line.size() - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (line[mid] >= 0) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            count += line.size() - left;
        }

        return count;
    }
};