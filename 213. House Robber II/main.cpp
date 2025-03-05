#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> subVec1(nums.begin(), nums.end() - 1);
        vector<int> subVec2(nums.begin() + 1, nums.end());

        return max(robHelper(subVec1), robHelper(subVec2));
    }

private:
    int robHelper(vector<int> &nums) {
        int size = nums.size();
        int a = 0;
        int b = 0;

        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                a = max(b, a + nums[i]);
            } else {
                b = max(a, b + nums[i]);
            }
        }

        return max(a, b);
    }
};

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> subVec1(nums.begin(), nums.end() - 1);
        vector<int> subVec2(nums.begin() + 1, nums.end());

        return max(robHelper(subVec1), robHelper(subVec2));
    }

private:
    int robHelper(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);

        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[size - 1];
    }
};

class Solution {
public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        int a = robHelper(nums, 0, size - 2);
        int b = robHelper(nums, 1, size - 1);

        return max(a, b);
    }

private:
    int robHelper(vector<int> &nums, int left, int right) {
        if (left > right) {
            return 0;
        }

        int a = 0;
        int b = 0;

        for (int i = 0; i < right + 1 - left; i++) {
            if (i % 2 == 0) {
                a = max(b, a + nums[left + i]);
            } else {
                b = max(a, b + nums[left + i]);
            }
        }

        return max(a, b);
    }
};

class Solution {
public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }

        return max(robHelper(nums, 0, size - 2), robHelper(nums, 1, size - 1));
    }

private:
    int robHelper(vector<int> &nums, int left, int right) {
        int prev1 = 0;
        int prev2 = 0;

        for (int i = 0; i < right + 1 - left; i++) {
            int cur = (prev1, prev2 + nums[left + i]);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};