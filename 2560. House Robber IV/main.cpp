#include <algorithm>
#include <limits>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    int minCapability(vector<int> &nums, int k) {
        int left = std::numeric_limits<int>::max();
        int right = std::numeric_limits<int>::min();
        int size = nums.size();

        for (const auto &num : nums) {
            if (num < left) {
                left = num;
            }
            if (num > right) {
                right = num;
            }
        }

        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            int index = 0;
            while (index < size) {
                if (nums[index] <= mid) {
                    count += 1;
                    index += 2;
                } else {
                    index += 1;
                }
            }

            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

class Solution {
public:
    int minCapability(vector<int> &nums, int k) {
        int left = std::numeric_limits<int>::max();
        int right = std::numeric_limits<int>::min();
        int size = nums.size();

        for (const auto &num : nums) {
            if (num < left) {
                left = num;
            }
            if (num > right) {
                right = num;
            }
        }

        while (left < right) {
            int mid = (left + right) / 2;
            if (canRob(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool canRob(vector<int> &nums, int max, int k) {
        int count = 0;
        int index = 0;
        while (index < nums.size()) {
            if (nums[index] <= max) {
                count += 1;
                index += 2;
            } else {
                index += 1;
            }
        }

        return count >= k;
    }
};