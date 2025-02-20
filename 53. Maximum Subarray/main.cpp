#include <vector>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max_sum = nums[0];
        int sum = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }

            if (max_sum < sum) {
                max_sum = sum;
            }
        }

        return max_sum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max_sum = std::numeric_limits<int>::min();
        int sum = 0;

        for (const auto &num : nums) {
            sum = std::max(sum + num, num);
            max_sum = std::max(max_sum, sum);
        }

        return max_sum;
    }
};