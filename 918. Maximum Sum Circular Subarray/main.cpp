#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int maxSum = numeric_limits<int>::min();
        int minSum = numeric_limits<int>::max();
        int curMax = 0;
        int curMin = 0;
        int totalSum = 0;

        for (const auto &num : nums) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            totalSum += num;
        }

        return (maxSum > 0) ? max(maxSum, totalSum - minSum) : maxSum;
    }
};