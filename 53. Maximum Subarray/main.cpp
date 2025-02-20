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

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }

private:
    int maxSubArrayHelper(vector<int> &nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int mid = (left + right) / 2;
        int left_max = maxSubArrayHelper(nums, left, mid);
        int right_max = maxSubArrayHelper(nums, mid + 1, right);
        int crossing_max = maxCrossingSubArray(nums, left, mid, right);

        return std::max(left_max, std::max(right_max, crossing_max));
    }

    int maxCrossingSubArray(vector<int> &nums, int left, int mid, int right) {
        int left_sum = std::numeric_limits<int>::min();
        int sum = 0;

        for (int i = mid; i > left  - 1; i--) {
            sum += nums[i];
            left_sum = std::max(left_sum, sum);
        }

        int right_sum = std::numeric_limits<int>::min();
        sum = 0;

        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            right_sum = std::max(right_sum, sum);
        }

        return left_sum + right_sum;
    }
};